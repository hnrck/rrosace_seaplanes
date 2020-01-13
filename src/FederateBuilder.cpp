//! \file FederateBuilder.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate builder body

#include <FederateBuilder.h>

using std::ostream;

auto FederateBuilder::set_federation(const Name &federation)
    -> FederateBuilder & {
  __federation_ = federation;
  return *this;
}

auto FederateBuilder::set_federate(const Name &federate) -> FederateBuilder & {
  __federate_ = federate;
  return *this;
}

auto FederateBuilder::set_fom(const Name &fom) -> FederateBuilder & {
  __fom_ = fom;
  return *this;
}

auto FederateBuilder::set_end_time(const Seaplanes::SeaplanesTime &endTime)
    -> FederateBuilder & {
  __end_time_ = endTime;
  return *this;
}

auto FederateBuilder::set_log_pointer(ostream *p_log) -> FederateBuilder & {
  __p_log_ = p_log;
  return *this;
}

auto FederateBuilder::set_output_pointer(std::ostream *p_output)
    -> FederateBuilder & {
  __p_output_ = p_output;
  return *this;
}

auto FederateBuilder::set_print_progression() -> FederateBuilder & {
  __progression_ = true;
  return *this;
}

auto FederateBuilder::add_model(UpModel &&up_model) -> FederateBuilder & {
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
                                    std::move(__models_), __end_time_, __p_log_,
                                    __p_output_, dt, __progression_);
}
