//! \file Federate.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate body

#include <Configuration.h>
#include <Federate.h>
#include <FederateBuilder.h>
#include <ModelFactory.h>

#include <rrosace.h>

Federate::Federate(Name federation, Name federate, Name fom,
                   VecUpModels up_models, Seaplanes::SeaplanesTime end_time,
                   double timestep)
    : Seaplanes::ProtoLogicalProcessor(
          std::move(federation), std::move(federate), std::move(fom),
          end_time.get_s(), timestep, timestep, Name()),
      __up_models_{std::move(up_models)} {}

void Federate::localsCalculation() {
  // TODO check scheduling
  for (auto &up_model : __up_models_) {
    up_model->step();
  }
}

void Federate::initDumpFiles() {}
void Federate::dumpValuesInFiles() {}
