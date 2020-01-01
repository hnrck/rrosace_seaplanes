//! \file Updaters.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values updaters implementations

#include <Updaters.h>

Updater::Updater(const Name &attribute_name, const Name &object_name,
                 const Name &instance_name, MapSpObjects &sp_objects_map,
                 MapUpObjectInstancesPublished &up_instances_published_map)
    : __sp_attribute_(Seaplanes::Attribute::create(attribute_name)) {
  const auto search_object = sp_objects_map.find(object_name);
  if (search_object == sp_objects_map.end()) {
    auto &&sp_object = Seaplanes::Object::create(object_name);
    sp_objects_map.insert({object_name, std::move(sp_object)});
  }

  const auto &sp_object = sp_objects_map.at(object_name);

  const auto &search_instance = up_instances_published_map.find(instance_name);

  if (search_instance == up_instances_published_map.end()) {
    auto &&up_instance =
        Seaplanes::ObjectInstancePublished::create(instance_name, sp_object);
    up_instances_published_map.insert({instance_name, std::move(up_instance)});
  }

  const auto &up_instance = up_instances_published_map.at(instance_name);

  up_instance->addAttribute(__sp_attribute_);
}

void Updater::sync() { update(); }

ThrustUpdater::ThrustUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ENGINE_THRUST, IBinder::ENGINE, IBinder::ENGINE_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

void ThrustUpdater::update() {
  Values::get_instance().t = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<ThrustUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrustUpdater>(sp_objects_map,
                                            up_instances_published_map));
}

ElevatorDeflectionUpdater::ElevatorDeflectionUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ELEVATOR_DEFLECTION, IBinder::ELEVATOR,
              IBinder::ELEVATOR_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void ElevatorDeflectionUpdater::update() {
  Values::get_instance().delta_e = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<ElevatorDeflectionUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionUpdater>(
          sp_objects_map, up_instances_published_map));
}

AltitudeUpdater::AltitudeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ALTITUDE, IBinder::AIRCRAFT, IBinder::AIRCRAFT_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

void AltitudeUpdater::update() {
  Values::get_instance().h = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<AltitudeUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class AltitudeUpdater>(sp_objects_map,
                                              up_instances_published_map));
}

VerticalSpeedUpdater::VerticalSpeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::VERTICAL_SPEED, IBinder::AIRCRAFT,
              IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void VerticalSpeedUpdater::update() {
  Values::get_instance().vz = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<VerticalSpeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class VerticalSpeedUpdater>(sp_objects_map,
                                                   up_instances_published_map));
}

TrueAirspeedUpdater::TrueAirspeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::TRUE_AIRSPEED, IBinder::AIRCRAFT,
              IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void TrueAirspeedUpdater::update() {
  Values::get_instance().va = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<TrueAirspeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class TrueAirspeedUpdater>(sp_objects_map,
                                                  up_instances_published_map));
}

PitchRateUpdater::PitchRateUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::PITCH_RATE, IBinder::AIRCRAFT,
              IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void PitchRateUpdater::update() {
  Values::get_instance().q = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<PitchRateUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class PitchRateUpdater>(sp_objects_map,
                                               up_instances_published_map));
}

VerticalAccelerationUpdater::VerticalAccelerationUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::VERTICAL_ACCELERATION, IBinder::AIRCRAFT,
              IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void VerticalAccelerationUpdater::update() {
  Values::get_instance().az = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<VerticalAccelerationUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class VerticalAccelerationUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredAltitudeUpdater::FilteredAltitudeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::FILTERED_ALTITUDE, IBinder::FILTERS,
              IBinder::FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void FilteredAltitudeUpdater::update() {
  Values::get_instance().h_f = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<FilteredAltitudeUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredAltitudeUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredVerticalSpeedUpdater::FilteredVerticalSpeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::FILTERED_VERTICAL_SPEED, IBinder::FILTERS,
              IBinder::FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void FilteredVerticalSpeedUpdater::update() {
  Values::get_instance().vz_f = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<FilteredVerticalSpeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredVerticalSpeedUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredTrueAirspeedUpdater::FilteredTrueAirspeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::FILTERED_TRUE_AIRSPEED, IBinder::FILTERS,
              IBinder::FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void FilteredTrueAirspeedUpdater::update() {
  Values::get_instance().va_f = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<FilteredTrueAirspeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredTrueAirspeedUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredPitchRateUpdater::FilteredPitchRateUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::FILTERED_PITCH_RATE, IBinder::FILTERS,
              IBinder::FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void FilteredPitchRateUpdater::update() {
  Values::get_instance().q_f = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<FilteredPitchRateUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredPitchRateUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredVerticalAccelerationUpdater::FilteredVerticalAccelerationUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::FILTERED_VERTICAL_ACCELERATION, IBinder::FILTERS,
              IBinder::FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void FilteredVerticalAccelerationUpdater::update() {
  Values::get_instance().az_f = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<FilteredVerticalAccelerationUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredVerticalAccelerationUpdater>(
          sp_objects_map, up_instances_published_map));
}

ModeUpdater::ModeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::MODE, IBinder::FLIGHT_MODE,
              IBinder::FLIGHT_MODE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void ModeUpdater::update() {
  Values::get_instance().mode =
      RROSACE::FlightMode::Mode(__sp_attribute_->getValue<int>());
}

template <>
UpUpdater Updater::create<ModeUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ModeUpdater>(sp_objects_map,
                                          up_instances_published_map));
}

AltitudeRefUpdater::AltitudeRefUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ALTITUDE_REF, IBinder::REFERENCE,
              IBinder::REFERENCE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void AltitudeRefUpdater::update() {
  Values::get_instance().h_c = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<AltitudeRefUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class AltitudeRefUpdater>(sp_objects_map,
                                                 up_instances_published_map));
}

VerticalSpeedRefUpdater::VerticalSpeedRefUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::VERTICAL_SPEED_REF, IBinder::REFERENCE,
              IBinder::REFERENCE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void VerticalSpeedRefUpdater::update() {
  Values::get_instance().vz_c = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<VerticalSpeedRefUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class VerticalSpeedRefUpdater>(
          sp_objects_map, up_instances_published_map));
}

TrueAirspeedRefUpdater::TrueAirspeedRefUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::TRUE_AIRSPEED_REF, IBinder::REFERENCE,
              IBinder::REFERENCE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void TrueAirspeedRefUpdater::update() {
  Values::get_instance().va_c = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<TrueAirspeedRefUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class TrueAirspeedRefUpdater>(
          sp_objects_map, up_instances_published_map));
}

ThrottleCommandUpdater::ThrottleCommandUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::THROTTLE_COMMAND, IBinder::CONTROL_COMMAND,
              IBinder::CONTROL_COMMAND_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void ThrottleCommandUpdater::update() {
  Values::get_instance().delta_th_c = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<ThrottleCommandUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrottleCommandUpdater>(
          sp_objects_map, up_instances_published_map));
}

ElevatorDeflectionCommandUpdater::ElevatorDeflectionCommandUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ELEVATOR_DEFLECTION_COMMAND, IBinder::CONTROL_COMMAND,
              IBinder::CONTROL_COMMAND_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

void ElevatorDeflectionCommandUpdater::update() {
  Values::get_instance().delta_e_c = __sp_attribute_->getValue<double>();
}

template <>
UpUpdater Updater::create<ElevatorDeflectionCommandUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionCommandUpdater>(
          sp_objects_map, up_instances_published_map));
}

ThrottleCommandPartialUpdater::ThrottleCommandPartialUpdater(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::THROTTLE_COMMAND_PARTIAL + std::to_string(index),
              IBinder::CONTROL_COMMAND_PARTIAL,
              IBinder::CONTROL_COMMAND_PARTIAL_INSTANCE, sp_objects_map,
              up_instances_published_map),
      __index_(index) {}

void ThrottleCommandPartialUpdater::update() {
  switch (__index_) {
  case 1:
    Values::get_instance().delta_th_c_partial_1 =
        __sp_attribute_->getValue<double>();
    break;
  case 2:
    Values::get_instance().delta_th_c_partial_2 =
        __sp_attribute_->getValue<double>();
    break;
  default:
    break;
  }
}

template <>
UpUpdater Updater::create<ThrottleCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrottleCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
UpUpdater Updater::create<ThrottleCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrottleCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}

RelayThrottleCommandPartialUpdater::RelayThrottleCommandPartialUpdater(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::RELAY_THROTTLE_COMMAND + std::to_string(index),
              IBinder::RELAY_CONTROL_COMMAND,
              IBinder::RELAY_CONTROL_COMMAND_INSTANCE, sp_objects_map,
              up_instances_published_map),
      __index_(index) {}

void RelayThrottleCommandPartialUpdater::update() {
  switch (__index_) {
  case 1:
    Values::get_instance().relay_delta_th_c_1 =
        __sp_attribute_->getValue<bool>()
            ? RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED
            : RROSACE::Cables::RelayState ::RROSACE_RELAY_CLOSED;
    break;
  case 2:
    Values::get_instance().relay_delta_th_c_2 =
        __sp_attribute_->getValue<bool>()
            ? RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED
            : RROSACE::Cables::RelayState ::RROSACE_RELAY_CLOSED;
    break;
  default:
    break;
  }
}

template <>
UpUpdater Updater::create<RelayThrottleCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayThrottleCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
UpUpdater Updater::create<RelayThrottleCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayThrottleCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}

ElevatorDeflectionCommandPartialUpdater::
    ElevatorDeflectionCommandPartialUpdater(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ELEVATOR_DEFLECTION_COMMAND_PARTIAL +
                  std::to_string(index),
              IBinder::CONTROL_COMMAND_PARTIAL,
              IBinder::CONTROL_COMMAND_PARTIAL_INSTANCE, sp_objects_map,
              up_instances_published_map),
      __index_(index) {}

void ElevatorDeflectionCommandPartialUpdater::update() {
  switch (__index_) {
  case 1:
    Values::get_instance().delta_e_c_partial_1 =
        __sp_attribute_->getValue<double>();
    break;
  case 2:
    Values::get_instance().delta_e_c_partial_2 =
        __sp_attribute_->getValue<double>();
    break;
  default:
    break;
  }
}

template <>
UpUpdater Updater::create<ElevatorDeflectionCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
UpUpdater Updater::create<ElevatorDeflectionCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}

RelayElevatorDeflectionCommandPartialUpdater::
    RelayElevatorDeflectionCommandPartialUpdater(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::RELAY_ELEVATOR_DEFLECTION_COMMAND +
                  std::to_string(index),
              IBinder::RELAY_CONTROL_COMMAND,
              IBinder::RELAY_CONTROL_COMMAND_INSTANCE, sp_objects_map,
              up_instances_published_map),
      __index_(index) {}

void RelayElevatorDeflectionCommandPartialUpdater::update() {
  switch (__index_) {
  case 1:
    Values::get_instance().relay_delta_th_c_1 =
        __sp_attribute_->getValue<bool>()
            ? RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED
            : RROSACE::Cables::RelayState ::RROSACE_RELAY_CLOSED;
    break;
  case 2:
    Values::get_instance().relay_delta_th_c_2 =
        __sp_attribute_->getValue<bool>()
            ? RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED
            : RROSACE::Cables::RelayState ::RROSACE_RELAY_CLOSED;
    break;
  default:
    break;
  }
}

template <>
UpUpdater Updater::create<RelayElevatorDeflectionCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
UpUpdater Updater::create<RelayElevatorDeflectionCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}
