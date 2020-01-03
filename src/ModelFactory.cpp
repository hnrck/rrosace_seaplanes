//! \file ModelFactory.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Model factory body

#include <ModelFactory.h>
#include <Values.h>

#include <rrosace.h>

#include <map>
#include <typeindex>

static const std::map<Name, std::pair<std::type_index, unsigned int>>
    NAME_TO_CLASS{
        {"engine", {typeid(RROSACE::Engine), 1}},
        {"elevator", {typeid(RROSACE::Elevator), 1}},
        {"flight_dynamics", {typeid(RROSACE::FlightDynamics), 1}},
        {"h_filter", {typeid(RROSACE::AltitudeFilter), 1}},
        {"vz_filter", {typeid(RROSACE::VerticalAirspeedFilter), 1}},
        {"va_filter", {typeid(RROSACE::TrueAirspeedFilter), 1}},
        {"q_filter", {typeid(RROSACE::PitchRateFilter), 1}},
        {"az_filter", {typeid(RROSACE::VerticalAccelerationFilter), 1}},
        {"flight_mode", {typeid(RROSACE::FlightMode), 1}},
        {"fcu", {typeid(RROSACE::FlightControlUnit), 1}},
        {"fcc1a", {typeid(RROSACE::FlightControlComputerCommand), 1}},
        {"fcc1b", {typeid(RROSACE::FlightControlComputerMonitor), 1}},
        {"fcc2a", {typeid(RROSACE::FlightControlComputerCommand), 2}},
        {"fcc2b", {typeid(RROSACE::FlightControlComputerMonitor), 2}},
        {"cables", {typeid(RROSACE::Cables), 1}},
    };

// TODO avoid multiple instantiation

// TODO complete
template <> UpModel ModelFactory::Generate<RROSACE::Engine, 1>() {
  auto &&values = Values::get_instance();

  values.delta_th_c_status.set_consumed_flag();
  values.t_status.set_produced_flag();
  return std::make_unique<RROSACE::Engine>(RROSACE::TAU, values.delta_th_c,
                                           values.t);
}

template <> UpModel ModelFactory::Generate<RROSACE::Elevator, 1>() {
  auto &&values = Values::get_instance();
  values.delta_e_c_status.set_consumed_flag();
  values.delta_e_status.set_produced_flag();
  return std::make_unique<RROSACE::Elevator>(RROSACE::OMEGA, RROSACE::XI,
                                             values.delta_e_c, values.delta_e);
}

template <> UpModel ModelFactory::Generate<RROSACE::FlightDynamics, 1>() {
  auto &&values = Values::get_instance();
  values.delta_e_status.set_consumed_flag();
  values.t_status.set_consumed_flag();
  values.h_status.set_produced_flag();
  values.vz_status.set_produced_flag();
  values.va_status.set_produced_flag();
  values.q_status.set_produced_flag();
  values.az_status.set_produced_flag();
  return std::make_unique<RROSACE::FlightDynamics>(
      values.delta_e, values.t, values.h, values.vz, values.va, values.q,
      values.az);
}

template <> UpModel ModelFactory::Generate<RROSACE::AltitudeFilter, 1>() {
  auto &&values = Values::get_instance();
  values.h_status.set_consumed_flag();
  values.h_f_status.set_produced_flag();
  return std::make_unique<RROSACE::AltitudeFilter>(values.h, values.h_f);
}

template <>
UpModel ModelFactory::Generate<RROSACE::VerticalAirspeedFilter, 1>() {
  auto &&values = Values::get_instance();
  values.vz_status.set_consumed_flag();
  values.vz_f_status.set_produced_flag();
  return std::make_unique<RROSACE::VerticalAirspeedFilter>(values.vz,
                                                           values.vz_f);
}

template <> UpModel ModelFactory::Generate<RROSACE::TrueAirspeedFilter, 1>() {
  auto &&values = Values::get_instance();
  values.va_status.set_consumed_flag();
  values.va_f_status.set_produced_flag();
  return std::make_unique<RROSACE::TrueAirspeedFilter>(values.va, values.va_f);
}

template <> UpModel ModelFactory::Generate<RROSACE::PitchRateFilter, 1>() {
  auto &&values = Values::get_instance();
  values.q_status.set_consumed_flag();
  values.q_f_status.set_produced_flag();
  return std::make_unique<RROSACE::PitchRateFilter>(values.q, values.q_f);
}

template <>
UpModel ModelFactory::Generate<RROSACE::VerticalAccelerationFilter, 1>() {
  auto &&values = Values::get_instance();
  values.az_status.set_consumed_flag();
  values.az_f_status.set_produced_flag();
  return std::make_unique<RROSACE::VerticalAccelerationFilter>(values.az,
                                                               values.az_f);
}

template <> UpModel ModelFactory::Generate<RROSACE::FlightMode, 1>() {
  auto &&values = Values::get_instance();
  values.mode_status.set_produced_flag();
  return std::make_unique<RROSACE::FlightMode>(values.mode, values.mode);
}

template <> UpModel ModelFactory::Generate<RROSACE::FlightControlUnit, 1>() {
  auto &&values = Values::get_instance();
  values.h_c_status.set_produced_flag();
  values.vz_c_status.set_produced_flag();
  values.va_c_status.set_produced_flag();
  return std::make_unique<RROSACE::FlightControlUnit>(values.h_c, values.vz_c,
                                                      values.va_c, values.h_c,
                                                      values.vz_c, values.va_c);
}

template <>
UpModel ModelFactory::Generate<RROSACE::FlightControlComputerCommand, 1>() {
  auto &&values = Values::get_instance();
  values.mode_status.set_consumed_flag();
  values.h_f_status.set_consumed_flag();
  values.vz_f_status.set_consumed_flag();
  values.va_f_status.set_consumed_flag();
  values.q_f_status.set_consumed_flag();
  values.az_f_status.set_consumed_flag();
  values.h_c_status.set_consumed_flag();
  values.vz_c_status.set_consumed_flag();
  values.va_c_status.set_consumed_flag();
  values.delta_e_c_partial_1_status.set_produced_flag();
  values.delta_th_c_partial_1_status.set_produced_flag();
  return std::make_unique<RROSACE::FlightControlComputer>(
      values.mode, values.h_f, values.vz_f, values.va_f, values.q_f,
      values.az_f, values.h_c, values.vz_c, values.va_c,
      values.delta_e_c_partial_1, values.delta_th_c_partial_1);
}

template <>
UpModel ModelFactory::Generate<RROSACE::FlightControlComputerMonitor, 1>() {
  auto &&values = Values::get_instance();
  values.mode_status.set_consumed_flag();
  values.h_f_status.set_consumed_flag();
  values.vz_f_status.set_consumed_flag();
  values.va_f_status.set_consumed_flag();
  values.q_f_status.set_consumed_flag();
  values.az_f_status.set_consumed_flag();
  values.h_c_status.set_consumed_flag();
  values.vz_c_status.set_consumed_flag();
  values.va_c_status.set_consumed_flag();
  values.delta_e_c_partial_1_status.set_consumed_flag();
  values.delta_th_c_partial_1_status.set_consumed_flag();
  values.other_master_in_law_1_status.set_consumed_flag();
  values.relay_delta_e_c_1_status.set_consumed_flag();
  values.relay_delta_th_c_1_status.set_consumed_flag();
  values.master_in_law_1_status.set_consumed_flag();
  return std::make_unique<RROSACE::FlightControlComputer>(
      values.mode, values.h_f, values.vz_f, values.va_f, values.q_f,
      values.az_f, values.h_c, values.vz_c, values.va_c,
      values.delta_e_c_partial_1, values.delta_th_c_partial_1,
      values.other_master_in_law_1, values.relay_delta_e_c_1,
      values.relay_delta_th_c_1, values.master_in_law_1);
}

template <>
UpModel ModelFactory::Generate<RROSACE::FlightControlComputerCommand, 2>() {
  auto &&values = Values::get_instance();
  values.mode_status.set_consumed_flag();
  values.h_f_status.set_consumed_flag();
  values.vz_f_status.set_consumed_flag();
  values.va_f_status.set_consumed_flag();
  values.q_f_status.set_consumed_flag();
  values.az_f_status.set_consumed_flag();
  values.h_c_status.set_consumed_flag();
  values.vz_c_status.set_consumed_flag();
  values.va_c_status.set_consumed_flag();
  values.delta_e_c_partial_2_status.set_produced_flag();
  values.delta_th_c_partial_2_status.set_produced_flag();
  return std::make_unique<RROSACE::FlightControlComputer>(
      values.mode, values.h_f, values.vz_f, values.va_f, values.q_f,
      values.az_f, values.h_c, values.vz_c, values.va_c,
      values.delta_e_c_partial_2, values.delta_th_c_partial_2);
}

template <>
UpModel ModelFactory::Generate<RROSACE::FlightControlComputerMonitor, 2>() {
  auto &&values = Values::get_instance();
  values.mode_status.set_consumed_flag();
  values.h_f_status.set_consumed_flag();
  values.vz_f_status.set_consumed_flag();
  values.va_f_status.set_consumed_flag();
  values.q_f_status.set_consumed_flag();
  values.az_f_status.set_consumed_flag();
  values.h_c_status.set_consumed_flag();
  values.vz_c_status.set_consumed_flag();
  values.va_c_status.set_consumed_flag();
  values.delta_e_c_partial_2_status.set_consumed_flag();
  values.delta_th_c_partial_2_status.set_consumed_flag();
  values.other_master_in_law_2_status.set_consumed_flag();
  values.relay_delta_e_c_2_status.set_consumed_flag();
  values.relay_delta_th_c_2_status.set_consumed_flag();
  values.master_in_law_2_status.set_consumed_flag();
  return std::make_unique<RROSACE::FlightControlComputer>(
      values.mode, values.h_f, values.vz_f, values.va_f, values.q_f,
      values.az_f, values.h_c, values.vz_c, values.va_c,
      values.delta_e_c_partial_2, values.delta_th_c_partial_2,
      values.other_master_in_law_2, values.relay_delta_e_c_2,
      values.relay_delta_th_c_2, values.master_in_law_2);
}

template <> UpModel ModelFactory::Generate<RROSACE::Cables, 1>() {
  auto &&values = Values::get_instance();
  values.delta_e_c_partial_1_status.set_produced_flag();
  values.delta_th_c_partial_1_status.set_produced_flag();
  values.relay_delta_e_c_1_status.set_produced_flag();
  values.relay_delta_th_c_1_status.set_produced_flag();
  values.delta_e_c_partial_2_status.set_produced_flag();
  values.delta_th_c_partial_2_status.set_produced_flag();
  values.relay_delta_e_c_2_status.set_produced_flag();
  values.relay_delta_th_c_2_status.set_produced_flag();
  values.delta_e_c_status.set_consumed_flag();
  values.delta_th_c_status.set_consumed_flag();
  return std::make_unique<RROSACE::Cables>(
      values.delta_e_c_partial_1, values.delta_th_c_partial_1,
      values.relay_delta_e_c_1, values.relay_delta_th_c_1,
      values.delta_e_c_partial_2, values.delta_th_c_partial_2,
      values.relay_delta_e_c_2, values.relay_delta_th_c_2, values.delta_e_c,
      values.delta_th_c);
}

UpModel ModelFactory::Generate(const Name &model_name) {
  try {

    auto model_type = NAME_TO_CLASS.at(model_name);

    if (model_type.first == typeid(RROSACE::Engine)) {
      return ModelFactory::Generate<RROSACE::Engine, 1>();
    } else if (model_type.first == typeid(RROSACE::Elevator)) {
      return ModelFactory::Generate<RROSACE::Elevator, 1>();
    } else if (model_type.first == typeid(RROSACE::FlightDynamics)) {
      return ModelFactory::Generate<RROSACE::FlightDynamics, 1>();
    } else if (model_type.first == typeid(RROSACE::AltitudeFilter)) {
      return ModelFactory::Generate<RROSACE::AltitudeFilter, 1>();
    } else if (model_type.first == typeid(RROSACE::VerticalAirspeedFilter)) {
      return ModelFactory::Generate<RROSACE::VerticalAirspeedFilter, 1>();
    } else if (model_type.first == typeid(RROSACE::TrueAirspeedFilter)) {
      return ModelFactory::Generate<RROSACE::TrueAirspeedFilter, 1>();
    } else if (model_type.first == typeid(RROSACE::PitchRateFilter)) {
      return ModelFactory::Generate<RROSACE::PitchRateFilter, 1>();
    } else if (model_type.first ==
               typeid(RROSACE::VerticalAccelerationFilter)) {
      return ModelFactory::Generate<RROSACE::VerticalAccelerationFilter, 1>();
    } else if (model_type.first == typeid(RROSACE::FlightMode)) {
      return ModelFactory::Generate<RROSACE::FlightMode, 1>();
    } else if (model_type.first == typeid(RROSACE::FlightControlUnit)) {
      return ModelFactory::Generate<RROSACE::FlightControlUnit, 1>();
    } else if (model_type.first ==
               typeid(RROSACE::FlightControlComputerCommand)) {
      if (model_type.second == 1) {
        return ModelFactory::Generate<RROSACE::FlightControlComputerCommand,
                                      1>();
      } else if (model_type.second == 2) {
        return ModelFactory::Generate<RROSACE::FlightControlComputerCommand,
                                      2>();
      }
    } else if (model_type.first ==
               typeid(RROSACE::FlightControlComputerMonitor)) {
      if (model_type.second == 1) {
        return ModelFactory::Generate<RROSACE::FlightControlComputerMonitor,
                                      1>();
      } else if (model_type.second == 2) {
        return ModelFactory::Generate<RROSACE::FlightControlComputerMonitor,
                                      2>();
      }
    } else if (model_type.first == typeid(RROSACE::Cables)) {
      return ModelFactory::Generate<RROSACE::Cables, 1>();
    }
  } catch (std::out_of_range &) {
    // TODO own class
    throw std::runtime_error("Model " + model_name + " does not exist");
  }

  // TODO own class
  throw std::runtime_error("Unable to generate model from name: " + model_name);
}
