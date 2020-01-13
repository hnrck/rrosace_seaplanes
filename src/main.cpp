//! \file main.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Main file

#include <Configuration.h>
#include <Federate.h>
#include <FederateBuilder.h>
#include <ModelFactory.h>

#include <Values.h>

auto main(int argc, char *argv[]) -> int {
  try {
    const auto &&configuration = Configuration(VecNames(argv, argv + argc));
    std::cout << configuration << std::endl;

    auto &&builder =
        FederateBuilder()
            .set_federation(configuration.get_federation())
            .set_fom(configuration.get_fom())
            .set_federate(configuration.get_federate())
            .set_end_time(configuration.get_end_time())
            .set_output_pointer(configuration.get_output_pointer());

    if (configuration.get_progression()) {
      builder.set_print_progression();
    }

    if (configuration.get_verbose()) {
      builder.set_log_pointer(configuration.get_log_pointer());
    }

    for (const auto &model_name : configuration.get_models()) {
      builder.add_model(ModelFactory::generate(model_name));
    }

    auto up_federate = builder.build();

    up_federate->run();

  } catch (const uninitializedConfiguration &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return 0;
}
