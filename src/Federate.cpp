//! \file Federate.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate body

#include <Configuration.h>
#include <Federate.h>
#include <Updaters.h>

Federate::Federate(Name federation, Name federate, Name fom,
                   VecUpModels up_models, Seaplanes::SeaplanesTime end_time,
                   double timestep)
    : Seaplanes::ProtoLogicalProcessor(
          std::move(federation), std::move(federate), std::move(fom),
          end_time.get_s(), timestep, timestep, Name()),
      __up_models_{std::move(up_models)} {
  // TODO algo for retrievers and updaters generation
  __retrievers_.push_back(Retriever::create<AltitudeRetriever>(
      __sp_objects_map_, __up_instances_subscribed_map_));
  __updaters_.push_back(Updater::create<AltitudeUpdater>(
      __sp_objects_map_, __up_instances_published_map_));
}

void Federate::localsCalculation() {
  for (auto &retriever : __retrievers_) {
    retriever->sync();
  }

  for (auto &up_model : __up_models_) {
    const size_t logical_time =
        static_cast<size_t>(getLocalTime().get_ms() / getTimeStep().get_ms());
    const size_t model_logical_period =
        static_cast<size_t>(up_model->get_dt() / getTimeStep().get_ms());
    if (logical_time % model_logical_period == 0) {
      up_model->step();
    }
  }

  for (auto &updater : __updaters_) {
    updater->sync();
  }
}

void Federate::initDumpFiles() {
  // TODO init dump files
}

void Federate::dumpValuesInFiles() {
  // TODO dump values
}
