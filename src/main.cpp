//! \file main.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Main file

#include <Configuration.h>
#include <Federate.h>
#include <FederateBuilder.h>
#include <ModelFactory.h>

int main(int argc, char *argv[]) {
  try {
    const auto &&configuration = Configuration(argc, argv);
    std::cout << configuration << std::endl;

    auto &&builder = FederateBuilder()
                         .setFederation(configuration.get_federation())
                         .setFom(configuration.get_fom())
                         .setFederate(configuration.get_federate())
                         .setEndTime(configuration.get_end_time());

    for (const auto &model_name : configuration.get_models()) {
      builder.addModel(ModelFactory::Generate(model_name));
    }

    auto up_federate = builder.build();

    up_federate->run();

  } catch (const uninitializedConfiguration &e) {
    std::cerr << e.what() << std::endl;
    exit(1);
  }
  return 0;
}
