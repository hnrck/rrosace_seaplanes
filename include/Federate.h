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

class Federate final : Seaplanes::ProtoLogicalProcessor {
private:
  VecUpModels __up_models_;

public:
  Federate(Name federation, Name federate, Name fom, VecUpModels up_models,
           Seaplanes::SeaplanesTime end_time, double timestep);

  void localsCalculation() final;
  void initDumpFiles() final;
  void dumpValuesInFiles() final;
};

#endif // RROSACE_SEAPLANES_FEDERATE_H
