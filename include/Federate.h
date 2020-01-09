//! \file Federate.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate

#ifndef RROSACE_SEAPLANES_FEDERATE_H
#define RROSACE_SEAPLANES_FEDERATE_H

#include <Common.h>
#include <FederateBuilder.h>
#include <ProtoLogicalProcessor.h>
#include <Retrievers.h>
#include <Updaters.h>

class Federate final : public Seaplanes::ProtoLogicalProcessor {
private:
  VecUpModels __up_models_;
  MapSpObjects __sp_objects_map_{};

  MapUpObjectInstancesPublished __up_instances_published_map_{};
  MapUpObjectInstancesSubscribed __up_instances_subscribed_map_{};

  VecUpRetrievers __retrievers_{};
  VecUpUpdaters __updaters_{};

public:
  Federate(Name federation, Name federate, Name fom, VecUpModels up_models,
           Seaplanes::SeaplanesTime end_time, double time_step);
  ~Federate() = default;

  Federate(const Federate &) = delete;
  auto operator=(const Federate &) = delete;

  Federate(Federate &&) = delete;
  auto operator=(Federate &&) = delete;

  auto localsCalculation() -> void final;
  auto initDumpFiles() -> void final;
  auto dumpValuesInFiles() -> void final;
};

#endif // RROSACE_SEAPLANES_FEDERATE_H
