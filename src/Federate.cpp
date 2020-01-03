//! \file Federate.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate body

#include <Configuration.h>
#include <Federate.h>
#include <Values.h>

Federate::Federate(Name federation, Name federate, Name fom,
                   VecUpModels up_models, Seaplanes::SeaplanesTime end_time,
                   double time_step)
    : Seaplanes::ProtoLogicalProcessor(
          std::move(federation), std::move(federate), std::move(fom),
          end_time.get_s(), time_step, time_step, Name()),
      __up_models_{std::move(up_models)} {

  for (auto &status_creators_tuple :
       Values::get_instance().status_creators_tuples_array) {

    if (std::get<0>(status_creators_tuple).sf.flags.produced == 0x1) {
      __updaters_.push_back(std::get<1>(status_creators_tuple)(
          __sp_objects_map_, __up_instances_published_map_));
    }

    if (std::get<0>(status_creators_tuple).sf.state ==
        Values::Status::State::SUBSCRIBE) {
      __retrievers_.push_back(std::get<2>(status_creators_tuple)(
          __sp_objects_map_, __up_instances_subscribed_map_));
    }
  }

  for (auto &sp_object : __sp_objects_map_) {
    addObjectClass(std::move(sp_object.second));
  }

  for (auto &up_instances_published : __up_instances_published_map_) {
    addPublishedObject(std::move(up_instances_published.second));
  }

  for (auto &up_instances_subscribed : __up_instances_subscribed_map_) {
    addSubscribedObject(std::move(up_instances_subscribed.second));
  }
}

void Federate::localsCalculation() {
  for (auto &retriever : __retrievers_) {
    retriever->sync();
  }

  for (auto &up_model : __up_models_) {
    const auto logical_time =
        static_cast<size_t>(getLocalTime().get_ms() / getTimeStep().get_ms());

    const auto model_logical_period =
        static_cast<size_t>(up_model->get_dt() / getTimeStep().get_s());

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
