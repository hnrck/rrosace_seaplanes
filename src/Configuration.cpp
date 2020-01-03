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
#define DEFAULT_END_TIME (50.)
#endif // DEFAULT_END_TIME

using std::vector;

const char *uninitializedConfiguration::what() const noexcept {
  return "Configuration is not initialized. Make sure to set at least "
         "federation, fom, federate name and one model.";
}

Configuration::Configuration()
    : __federation_{}, __fom_{}, __federate_{},
      __verbose_{false}, __log_{std::clog}, __output_{std::cout}, __models_{},
      __end_time_(Seaplanes::SeaplanesTime(DEFAULT_END_TIME)),
      __federation_set_(false), __fom_set_(false) {}

Configuration::Configuration(int argc, char *argv[]) : Configuration() {
  parse_arguments(argc, argv);
}

void Configuration::parse_arguments(int argc, char *argv[]) noexcept(false) {
  const auto *short_opts = "f:m:n:e:vh";
  const auto long_opts =
      std::vector<option>{{"federation", required_argument, nullptr, 'f'},
                          {"fom", required_argument, nullptr, 'm'},
                          {"name", required_argument, nullptr, 'n'},
                          {"end", required_argument, nullptr, 'e'},
                          {"verbose", no_argument, nullptr, 'v'},
                          {"help", no_argument, nullptr, 'h'},
                          {nullptr, no_argument, nullptr, 0}};

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

Name Configuration::get_federation() const { return __federation_; }
Name Configuration::get_fom() const { return __fom_; }
Name Configuration::get_federate() const { return __federate_; }
bool Configuration::get_verbose() const { return __verbose_; }
std::ostream &Configuration::get_log() const { return __log_; }
std::ostream &Configuration::get_output() const { return __output_; }
std::vector<Name> Configuration::get_models() const { return __models_; }
Seaplanes::SeaplanesTime Configuration::get_end_time() const {
  return __end_time_;
}

std::ostream &operator<<(std::ostream &stream,
                         const Configuration &configuration) {
  stream << "Configuration" << std::endl;
  if (!configuration.initialized()) {
    stream << "\tUninitialized" << std::endl;
  } else {
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
  }
  return (stream);
}

void Configuration::print_help(const char exec_name[],
                               std::ostream &stream) const {
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

bool Configuration::initialized() const {
  return (__federation_set_ && __fom_set_ && __federate_set_ &&
          !__models_.empty());
}
