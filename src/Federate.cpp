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
  for (auto &up_model : __up_models_) {
    const size_t logical_time =
        static_cast<size_t>(getLocalTime().get_ms() / getTimeStep().get_ms());
    const size_t model_logical_period =
        static_cast<size_t>(up_model->get_dt() / getTimeStep().get_ms());
    if (logical_time % model_logical_period == 0) {
      up_model->step();
    }
  }
}

void Federate::initDumpFiles() {}
void Federate::dumpValuesInFiles() {}
