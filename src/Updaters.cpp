//! \file Updaters.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values updaters implementations

#include <Updaters.h>
#include <Values.h>

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

auto Updater::sync() -> void { update(); }

ThrustUpdater::ThrustUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(ENGINE_THRUST, ENGINE, ENGINE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto ThrustUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().t);
}

template <>
auto Updater::create<ThrustUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrustUpdater>(sp_objects_map,
                                            up_instances_published_map));
}

ElevatorDeflectionUpdater::ElevatorDeflectionUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(ELEVATOR_DEFLECTION, ELEVATOR, ELEVATOR_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto ElevatorDeflectionUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().delta_e);
}

template <>
auto Updater::create<ElevatorDeflectionUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionUpdater>(
          sp_objects_map, up_instances_published_map));
}

AltitudeUpdater::AltitudeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(ALTITUDE, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto AltitudeUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().h);
}

template <>
auto Updater::create<AltitudeUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class AltitudeUpdater>(sp_objects_map,
                                              up_instances_published_map));
}

VerticalSpeedUpdater::VerticalSpeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(VERTICAL_SPEED, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto VerticalSpeedUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().vz);
}

template <>
auto Updater::create<VerticalSpeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class VerticalSpeedUpdater>(sp_objects_map,
                                                   up_instances_published_map));
}

TrueAirspeedUpdater::TrueAirspeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(TRUE_AIRSPEED, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto TrueAirspeedUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().va);
}

template <>
auto Updater::create<TrueAirspeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class TrueAirspeedUpdater>(sp_objects_map,
                                                  up_instances_published_map));
}

PitchRateUpdater::PitchRateUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(PITCH_RATE, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto PitchRateUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().q);
}

template <>
auto Updater::create<PitchRateUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class PitchRateUpdater>(sp_objects_map,
                                               up_instances_published_map));
}

VerticalAccelerationUpdater::VerticalAccelerationUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(VERTICAL_ACCELERATION, AIRCRAFT, AIRCRAFT_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

auto VerticalAccelerationUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().az);
}

template <>
auto Updater::create<VerticalAccelerationUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class VerticalAccelerationUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredAltitudeUpdater::FilteredAltitudeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(FILTERED_ALTITUDE, FILTERS, FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto FilteredAltitudeUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().h_f);
}

template <>
auto Updater::create<FilteredAltitudeUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredAltitudeUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredVerticalSpeedUpdater::FilteredVerticalSpeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(FILTERED_VERTICAL_SPEED, FILTERS, FILTERS_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

auto FilteredVerticalSpeedUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().vz_f);
}

template <>
auto Updater::create<FilteredVerticalSpeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredVerticalSpeedUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredTrueAirspeedUpdater::FilteredTrueAirspeedUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(FILTERED_TRUE_AIRSPEED, FILTERS, FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto FilteredTrueAirspeedUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().va_f);
}

template <>
auto Updater::create<FilteredTrueAirspeedUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredTrueAirspeedUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredPitchRateUpdater::FilteredPitchRateUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(FILTERED_PITCH_RATE, FILTERS, FILTERS_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto FilteredPitchRateUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().q_f);
}

template <>
auto Updater::create<FilteredPitchRateUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredPitchRateUpdater>(
          sp_objects_map, up_instances_published_map));
}

FilteredVerticalAccelerationUpdater::FilteredVerticalAccelerationUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(FILTERED_VERTICAL_ACCELERATION, FILTERS, FILTERS_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

auto FilteredVerticalAccelerationUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().az_f);
}

template <>
auto Updater::create<FilteredVerticalAccelerationUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class FilteredVerticalAccelerationUpdater>(
          sp_objects_map, up_instances_published_map));
}

ModeUpdater::ModeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(MODE, FLIGHT_MODE, FLIGHT_MODE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto ModeUpdater::update() -> void {
  __sp_attribute_->setValue<int>(static_cast<int>(Values::get_instance().mode));
}

template <>
auto Updater::create<ModeUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ModeUpdater>(sp_objects_map,
                                          up_instances_published_map));
}

AltitudeRefUpdater::AltitudeRefUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(ALTITUDE_REF, REFERENCE, REFERENCE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto AltitudeRefUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().h_c);
}

template <>
auto Updater::create<AltitudeRefUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class AltitudeRefUpdater>(sp_objects_map,
                                                 up_instances_published_map));
}

VerticalSpeedRefUpdater::VerticalSpeedRefUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(VERTICAL_SPEED_REF, REFERENCE, REFERENCE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto VerticalSpeedRefUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().vz_c);
}

template <>
auto Updater::create<VerticalSpeedRefUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class VerticalSpeedRefUpdater>(
          sp_objects_map, up_instances_published_map));
}

TrueAirspeedRefUpdater::TrueAirspeedRefUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(TRUE_AIRSPEED_REF, REFERENCE, REFERENCE_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto TrueAirspeedRefUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().va_c);
}

template <>
auto Updater::create<TrueAirspeedRefUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class TrueAirspeedRefUpdater>(
          sp_objects_map, up_instances_published_map));
}

ThrottleCommandUpdater::ThrottleCommandUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(THROTTLE_COMMAND, CONTROL_COMMAND, CONTROL_COMMAND_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

auto ThrottleCommandUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().delta_th_c);
}

template <>
auto Updater::create<ThrottleCommandUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrottleCommandUpdater>(
          sp_objects_map, up_instances_published_map));
}

ElevatorDeflectionCommandUpdater::ElevatorDeflectionCommandUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(ELEVATOR_DEFLECTION_COMMAND, CONTROL_COMMAND,
              CONTROL_COMMAND_INSTANCE, sp_objects_map,
              up_instances_published_map) {}

auto ElevatorDeflectionCommandUpdater::update() -> void {
  __sp_attribute_->setValue<double>(Values::get_instance().delta_e_c);
}

template <>
auto Updater::create<ElevatorDeflectionCommandUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionCommandUpdater>(
          sp_objects_map, up_instances_published_map));
}

ThrottleCommandPartialUpdater::ThrottleCommandPartialUpdater(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(THROTTLE_COMMAND_PARTIAL, CONTROL_COMMAND_PARTIAL,
              CONTROL_COMMAND_PARTIAL_INSTANCE + std::to_string(index),
              sp_objects_map, up_instances_published_map),
      __index_(index) {}

auto ThrottleCommandPartialUpdater::update() -> void {
  switch (__index_) {
  case 1:
    __sp_attribute_->setValue<double>(
        Values::get_instance().delta_th_c_partial_1);
    break;
  case 2:
    __sp_attribute_->setValue<double>(
        Values::get_instance().delta_th_c_partial_2);
    break;
  default:
    break;
  }
}

template <>
auto Updater::create<ThrottleCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrottleCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
auto Updater::create<ThrottleCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ThrottleCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}

RelayThrottleCommandPartialUpdater::RelayThrottleCommandPartialUpdater(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(RELAY_THROTTLE_COMMAND, RELAY_CONTROL_COMMAND,
              RELAY_CONTROL_COMMAND_INSTANCE + std::to_string(index),
              sp_objects_map, up_instances_published_map),
      __index_(index) {}

auto RelayThrottleCommandPartialUpdater::update() -> void {
  switch (__index_) {
  case 1:
    __sp_attribute_->setValue<bool>(
        Values::get_instance().relay_delta_th_c_1 ==
        RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED);
    break;
  case 2:
    __sp_attribute_->setValue<bool>(
        Values::get_instance().relay_delta_th_c_2 ==
        RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED);
    break;
  default:
    break;
  }
}

template <>
auto Updater::create<RelayThrottleCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayThrottleCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
auto Updater::create<RelayThrottleCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayThrottleCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}

ElevatorDeflectionCommandPartialUpdater::
    ElevatorDeflectionCommandPartialUpdater(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(ELEVATOR_DEFLECTION_COMMAND_PARTIAL, CONTROL_COMMAND_PARTIAL,
              CONTROL_COMMAND_PARTIAL_INSTANCE + std::to_string(index),
              sp_objects_map, up_instances_published_map),
      __index_(index) {}

auto ElevatorDeflectionCommandPartialUpdater::update() -> void {
  switch (__index_) {
  case 1:
    __sp_attribute_->setValue<double>(
        Values::get_instance().delta_e_c_partial_1);
    break;
  case 2:
    __sp_attribute_->setValue<double>(
        Values::get_instance().delta_e_c_partial_2);
    break;
  default:
    break;
  }
}

template <>
auto Updater::create<ElevatorDeflectionCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
auto Updater::create<ElevatorDeflectionCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}

RelayElevatorDeflectionCommandPartialUpdater::
    RelayElevatorDeflectionCommandPartialUpdater(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(RELAY_ELEVATOR_DEFLECTION_COMMAND, RELAY_CONTROL_COMMAND,
              RELAY_CONTROL_COMMAND_INSTANCE + std::to_string(index),
              sp_objects_map, up_instances_published_map),
      __index_(index) {}

auto RelayElevatorDeflectionCommandPartialUpdater::update() -> void {
  switch (__index_) {
  case 1:
    __sp_attribute_->setValue<bool>(
        Values::get_instance().relay_delta_e_c_1 ==
        RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED);
    break;
  case 2:
    __sp_attribute_->setValue<bool>(
        Values::get_instance().relay_delta_e_c_2 ==
        RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED);
    break;
  default:
    break;
  }
}

template <>
auto Updater::create<RelayElevatorDeflectionCommandPartialUpdater, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialUpdater>(
          1, sp_objects_map, up_instances_published_map));
}

template <>
auto Updater::create<RelayElevatorDeflectionCommandPartialUpdater, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) -> UpUpdater {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialUpdater>(
          2, sp_objects_map, up_instances_published_map));
}
