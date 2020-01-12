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
  std::ostream *__p_log_{&std::clog};
  std::ostream *__p_output_{&std::cout};

  VecUpModels __models_{};

public:
  FederateBuilder() = default;
  virtual ~FederateBuilder() = default;

  FederateBuilder(const FederateBuilder &) = delete;
  auto operator=(const FederateBuilder &) = delete;

  FederateBuilder(FederateBuilder &&) = default;
  auto operator=(FederateBuilder &&) -> FederateBuilder & = default;

  auto setFederation(const Name &federation) -> FederateBuilder &;
  auto setFederate(const Name &federate) -> FederateBuilder &;
  auto setFom(const Name &fom) -> FederateBuilder &;
  auto setEndTime(const Seaplanes::SeaplanesTime &endTime) -> FederateBuilder &;
  auto setLogPointer(std::ostream *p_log) -> FederateBuilder &;
  auto setOutputPointer(std::ostream *p_output) -> FederateBuilder &;
  auto addModel(UpModel &&up_model) -> FederateBuilder &;

  auto build() -> UpFederate;
};

#endif // RROSACE_SEAPLANES_FEDERATEBUILDER_H
