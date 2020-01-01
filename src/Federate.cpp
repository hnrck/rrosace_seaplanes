//! \file Federate.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate body

#include <Configuration.h>
#include <Federate.h>
#include <Updaters.h>
#include <Values.h>

Federate::Federate(Name federation, Name federate, Name fom,
                   VecUpModels up_models, Seaplanes::SeaplanesTime end_time,
                   double timestep)
    : Seaplanes::ProtoLogicalProcessor(
          std::move(federation), std::move(federate), std::move(fom),
          end_time.get_s(), timestep, timestep, Name()),
      __up_models_{std::move(up_models)} {
  for (auto &status_creators_tuple :
       Values::get_instance().status_creators_tuples_array) {
    if (std::get<0>(status_creators_tuple).state ==
        Values::Status::State::PUBLISH) {
      __updaters_.push_back(std::get<1>(status_creators_tuple)(
          __sp_objects_map_, __up_instances_published_map_));
    }
    if (std::get<0>(status_creators_tuple).state ==
        Values::Status::State::SUBSCRIBE) {
      __retrievers_.push_back(std::get<2>(status_creators_tuple)(
          __sp_objects_map_, __up_instances_subscribed_map_));
    }
  }
  // TODO move objects
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
