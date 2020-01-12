//! \file FederateBuilder.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate builder body

#include <FederateBuilder.h>

using std::ostream;

auto FederateBuilder::setFederation(const Name &federation)
    -> FederateBuilder & {
  __federation_ = federation;
  return *this;
}

auto FederateBuilder::setFederate(const Name &federate) -> FederateBuilder & {
  __federate_ = federate;
  return *this;
}

auto FederateBuilder::setFom(const Name &fom) -> FederateBuilder & {
  __fom_ = fom;
  return *this;
}

auto FederateBuilder::setEndTime(const Seaplanes::SeaplanesTime &endTime)
    -> FederateBuilder & {
  __end_time_ = endTime;
  return *this;
}

auto FederateBuilder::setLog(ostream &log)
-> FederateBuilder & {
  __p_log_ = &log;
  return *this;
}

auto FederateBuilder::addModel(UpModel &&up_model) -> FederateBuilder & {
  __models_.push_back(std::move(up_model));
  return *this;
}

auto FederateBuilder::build() -> UpFederate {
  auto dt = std::numeric_limits<double>::max();

  for (auto &model : __models_) {
    if (dt > model->get_dt()) {
      dt = model->get_dt();
    }
  }

  return std::make_unique<Federate>(std::move(__federation_),
                                    std::move(__federate_), std::move(__fom_),
                                    std::move(__models_), __end_time_, __p_log_, dt);
}
