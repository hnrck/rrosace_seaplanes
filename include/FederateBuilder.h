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

  VecUpModels __models_{};

  // TODO values to print
public:
  FederateBuilder();
  virtual ~FederateBuilder();

  FederateBuilder(const FederateBuilder &) = delete;
  FederateBuilder &operator=(const FederateBuilder &) = delete;

  FederateBuilder(FederateBuilder &&) = default;
  FederateBuilder &operator=(FederateBuilder &&) = default;

  FederateBuilder &setFederation(const Name &federation);
  FederateBuilder &setFederate(const Name &federate);
  FederateBuilder &setFom(const Name &fom);
  FederateBuilder &setEndTime(const Seaplanes::SeaplanesTime &endTime);
  FederateBuilder &addModel(UpModel &&up_model);

  UpFederate build();
};

#endif // RROSACE_SEAPLANES_FEDERATEBUILDER_H
