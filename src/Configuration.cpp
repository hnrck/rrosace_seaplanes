//! \file Configuration.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Configuration parser body

#include <Configuration.h>

#include <SeaplanesTime.h>

#include <getopt.h>
#include <limits>
#include <sstream>
#include <vector>

#ifndef DEFAULT_END_TIME
constexpr const float DEFAULT_END_TIME = 50.;
#endif // DEFAULT_END_TIME

using std::vector;

auto uninitializedConfiguration::what() const noexcept -> const char * {
  return "Configuration is not initialized. Make sure to set at least "
         "federation, fom, federate name and one model.";
}

Configuration::Configuration()
    : __end_time_(Seaplanes::SeaplanesTime(DEFAULT_END_TIME)) {}

Configuration::Configuration(const VecNames &vec_args) : Configuration() {
  parse_arguments(vec_args);
}

Configuration::~Configuration() {
  if (__output_file_.is_open()) {
    __output_file_.close();
  }
}

auto Configuration::parse_arguments(const VecNames &vec_args) noexcept(false)
    -> void {
  const auto *short_opts = "f:m:n:e:o:vh";
  const auto long_opts =
      std::vector<option>{{"federation", required_argument, nullptr, 'f'},
                          {"fom", required_argument, nullptr, 'm'},
                          {"name", required_argument, nullptr, 'n'},
                          {"end", required_argument, nullptr, 'e'},
                          {"output", required_argument, nullptr, 'o'},
                          {"verbose", no_argument, nullptr, 'v'},
                          {"help", no_argument, nullptr, 'h'},
                          {nullptr, no_argument, nullptr, 0}};

  auto vec_up_args = std::vector<std::unique_ptr<const char[]>>();
  auto vec_c_args = std::vector<char *>();
  for (const auto &arg : vec_args) {
    auto up_c_arg = std::unique_ptr<char[]>(new char[arg.size() + 1]);
    memcpy(up_c_arg.get(), arg.c_str(), arg.size());
    up_c_arg[arg.size()] = '\0';
    vec_c_args.push_back(up_c_arg.get());
    vec_up_args.push_back(std::move(up_c_arg));
  }
  const auto argc = vec_c_args.size();
  const auto argv = vec_c_args.data();

  while (true) {
    const auto option =
        getopt_long(argc, argv, short_opts, long_opts.data(), nullptr);

    if (-1 == option) {
      break;
    }

    switch (option) {
    case 'f':
      __federation_ = optarg;
      __federation_set_ = true;
      break;

    case 'm':
      __fom_ = optarg;
      __fom_set_ = true;
      break;

    case 'n':
      __federate_ = optarg;
      __federate_set_ = true;
      break;

    case 'e':
      __end_time_ = Seaplanes::SeaplanesTime(optarg);
      break;

    case 'o':
      __output_file_.open(optarg, std::ofstream::out);
      __p_output_ = &__output_file_;
      break;

    case 'v':
      __verbose_ = true;
      break;

    case 'h':
    case '?':
      print_help(argv[0], std::cout);
      exit(0);

    default:
      print_help(argv[0], std::cerr);
      exit(1);
    }
  }

  std::copy(&argv[optind], &argv[argc], std::back_inserter(__models_));

  if (!initialized()) {
    throw uninitializedConfiguration();
  }
}

auto Configuration::get_federation() const -> Name { return __federation_; }

auto Configuration::get_fom() const -> Name { return __fom_; }

auto Configuration::get_federate() const -> Name { return __federate_; }

auto Configuration::get_verbose() const -> bool { return __verbose_; }

auto Configuration::get_log_pointer() const -> std::ostream * {
  return __p_log_;
}

auto Configuration::get_output_pointer() const -> std::ostream * {
  return __p_output_;
}

auto Configuration::get_models() const -> std::vector<Name> {
  return __models_;
}

auto Configuration::get_end_time() const -> Seaplanes::SeaplanesTime {
  return __end_time_;
}

auto operator<<(std::ostream &stream, const Configuration &configuration)
    -> std::ostream & {

  if (!configuration.initialized()) {
    throw(std::runtime_error("Configuration uninitialized"));
  }

  stream << "Configuration" << std::endl;
  stream << "\tHLA:" << std::endl;
  stream << "\t\tfederation:   " << configuration.__federation_ << std::endl;
  stream << "\t\tFOM:          " << configuration.__fom_ << std::endl;
  stream << "\t\tfederate:     " << configuration.__federate_ << std::endl;

  stream << "\tSeaplanes:" << std::endl;
  stream << "\t\tdeadline:     " << configuration.__end_time_ << std::endl;
  stream << "\t\tverbose:      " << std::boolalpha << configuration.__verbose_

         << std::endl;
  stream << "\t\tmodels:" << std::endl << "\t\t\t";
  std::copy(configuration.__models_.begin(), configuration.__models_.end(),
            std::ostream_iterator<Name>(std::cout, " "));
  stream << std::endl;

  return (stream);
}

auto Configuration::print_help(const Name &exec_name,
                               std::ostream &stream) const -> void {
  stream << "Configuration module:" << std::endl;
  stream << std::endl;

  stream << "Mandatory:" << std::endl;
  stream << "\t--federation, -f <federation>: Set the Federation" << std::endl;
  stream << "\t--fom,        -m <fom>:        Set the FOM" << std::endl;
  stream << "\t--name, -n <name>:             Set the federate name"
         << std::endl;
  stream << std::endl;
  stream << "\t-- <model 1> [ ... ]:          Set the models to schedule"
         << std::endl;
  stream << std::endl;
  stream << std::endl;

  stream << "Optional:" << std::endl;
  stream << "\t--end_time,  -e <end_time>:    Set the end (default "
         << DEFAULT_END_TIME << "s)" << std::endl;
  stream << std::endl;

  stream << "Example:" << std::endl;
  stream << exec_name << " -- fcc1a fcc1b" << std::endl;
}

auto Configuration::initialized() const -> bool {
  return (__federation_set_ && __fom_set_ && __federate_set_ &&
          !__models_.empty());
}
