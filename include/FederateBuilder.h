//! \file FederateBuilder.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate Builder

#ifndef RROSACE_SEAPLANES_FEDERATEBUILDER_H
#define RROSACE_SEAPLANES_FEDERATEBUILDER_H

#include <Common.h>
#include <Configuration.h>
#include <Federate.h>

class FederateBuilder final {
private:
  Name __federation_{};
  Name __federate_{};
  Name __fom_{};
  Seaplanes::SeaplanesTime __end_time_{0.};
  std::ostream *__p_log_{nullptr};
  std::ostream *__p_output_{&std::cout};
  bool __progression_{false};

  VecUpModels __models_{};

public:
  FederateBuilder() = default;
  virtual ~FederateBuilder() = default;

  FederateBuilder(const FederateBuilder &) = delete;
  auto operator=(const FederateBuilder &) = delete;

  FederateBuilder(FederateBuilder &&) = default;
  auto operator=(FederateBuilder &&) -> FederateBuilder & = default;

  auto set_federation(const Name &federation) -> FederateBuilder &;
  auto set_federate(const Name &federate) -> FederateBuilder &;
  auto set_fom(const Name &fom) -> FederateBuilder &;
  auto set_end_time(const Seaplanes::SeaplanesTime &endTime) -> FederateBuilder &;
  auto set_log_pointer(std::ostream *p_log) -> FederateBuilder &;
  auto set_output_pointer(std::ostream *p_output) -> FederateBuilder &;
  auto set_print_progression() -> FederateBuilder &;
  auto add_model(UpModel &&up_model) -> FederateBuilder &;

  auto build() -> UpFederate;
};

#endif // RROSACE_SEAPLANES_FEDERATEBUILDER_H
