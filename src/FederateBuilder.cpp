//! \file FederateBuilder.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate builder body

#include <FederateBuilder.h>
#include <ModelFactory.h>

FederateBuilder::FederateBuilder() = default;
FederateBuilder::~FederateBuilder() = default;

FederateBuilder &FederateBuilder::setFederation(const Name &federation) {
  __federation_ = federation;
  return *this;
}

FederateBuilder &FederateBuilder::setFederate(const Name &federate) {
  __federate_ = federate;
  return *this;
}

FederateBuilder &FederateBuilder::setFom(const Name &fom) {
  __fom_ = fom;
  return *this;
}

FederateBuilder &
FederateBuilder::setEndTime(const Seaplanes::SeaplanesTime &endTime) {
  __end_time_ = endTime;
  return *this;
}

FederateBuilder &FederateBuilder::addModel(UpModel &&up_model) {
  __models_.push_back(std::move(up_model));
  return *this;
}

UpFederate FederateBuilder::build() {
  // TODO implement
  auto dt = 0.;

  for (auto &model : __models_) {
    if (dt > model->get_dt()) {
      dt = model->get_dt();
    }
  }

  return std::make_unique<Federate>(std::move(__federation_),
                                    std::move(__federate_), std::move(__fom_),
                                    std::move(__models_), __end_time_, dt);
}
