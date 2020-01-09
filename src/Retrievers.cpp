//! \file Retrievers.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values retrievers implementations

#include <Retrievers.h>
#include <Values.h>

Retriever::Retriever(
    const Name &attribute_name, const Name &object_name,
    const Name &instance_name, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : __sp_attribute_(Seaplanes::Attribute::create(attribute_name)) {
  const auto search_object = sp_objects_map.find(object_name);
  if (search_object == sp_objects_map.end()) {
    auto &&sp_object = Seaplanes::Object::create(object_name);
    sp_objects_map.insert({object_name, std::move(sp_object)});
  }

  const auto &sp_object = sp_objects_map.at(object_name);

  const auto &search_instance = up_instances_subscribed_map.find(instance_name);

  if (search_instance == up_instances_subscribed_map.end()) {
    auto &&up_instance =
        Seaplanes::ObjectInstanceSubscribed::create(instance_name, sp_object);
    up_instances_subscribed_map.insert({instance_name, std::move(up_instance)});
  }

  const auto &up_instance = up_instances_subscribed_map.at(instance_name);

  up_instance->addAttribute(__sp_attribute_);
}

auto Retriever::sync() -> void { retrieve(); }

ThrustRetriever::ThrustRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(ENGINE_THRUST, ENGINE, ENGINE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto ThrustRetriever::retrieve() -> void {
  Values::get_instance().t = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<ThrustRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrustRetriever>(sp_objects_map,
                                              up_instances_subscribed_map));
}

ElevatorDeflectionRetriever::ElevatorDeflectionRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(ELEVATOR_DEFLECTION, ELEVATOR, ELEVATOR_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto ElevatorDeflectionRetriever::retrieve() -> void {
  Values::get_instance().delta_e = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<ElevatorDeflectionRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

AltitudeRetriever::AltitudeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(ALTITUDE, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto AltitudeRetriever::retrieve() -> void {
  Values::get_instance().h = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<AltitudeRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class AltitudeRetriever>(sp_objects_map,
                                                up_instances_subscribed_map));
}

VerticalSpeedRetriever::VerticalSpeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(VERTICAL_SPEED, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto VerticalSpeedRetriever::retrieve() -> void {
  Values::get_instance().vz = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<VerticalSpeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class VerticalSpeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

TrueAirspeedRetriever::TrueAirspeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(TRUE_AIRSPEED, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto TrueAirspeedRetriever::retrieve() -> void {
  Values::get_instance().va = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<TrueAirspeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class TrueAirspeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

PitchRateRetriever::PitchRateRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(PITCH_RATE, AIRCRAFT, AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto PitchRateRetriever::retrieve() -> void {
  Values::get_instance().q = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<PitchRateRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class PitchRateRetriever>(sp_objects_map,
                                                 up_instances_subscribed_map));
}

VerticalAccelerationRetriever::VerticalAccelerationRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(VERTICAL_ACCELERATION, AIRCRAFT, AIRCRAFT_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto VerticalAccelerationRetriever::retrieve() -> void {
  Values::get_instance().az = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<VerticalAccelerationRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class VerticalAccelerationRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredAltitudeRetriever::FilteredAltitudeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(FILTERED_ALTITUDE, FILTERS, FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto FilteredAltitudeRetriever::retrieve() -> void {
  Values::get_instance().h_f = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<FilteredAltitudeRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredAltitudeRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredVerticalSpeedRetriever::FilteredVerticalSpeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(FILTERED_VERTICAL_SPEED, FILTERS, FILTERS_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto FilteredVerticalSpeedRetriever::retrieve() -> void {
  Values::get_instance().vz_f = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<FilteredVerticalSpeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredVerticalSpeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredTrueAirspeedRetriever::FilteredTrueAirspeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(FILTERED_TRUE_AIRSPEED, FILTERS, FILTERS_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto FilteredTrueAirspeedRetriever::retrieve() -> void {
  Values::get_instance().va_f = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<FilteredTrueAirspeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredTrueAirspeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredPitchRateRetriever::FilteredPitchRateRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(FILTERED_PITCH_RATE, FILTERS, FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto FilteredPitchRateRetriever::retrieve() -> void {
  Values::get_instance().q_f = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<FilteredPitchRateRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredPitchRateRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredVerticalAccelerationRetriever::FilteredVerticalAccelerationRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(FILTERED_VERTICAL_ACCELERATION, FILTERS, FILTERS_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto FilteredVerticalAccelerationRetriever::retrieve() -> void {
  Values::get_instance().az_f = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<FilteredVerticalAccelerationRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredVerticalAccelerationRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ModeRetriever::ModeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(MODE, FLIGHT_MODE, FLIGHT_MODE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto ModeRetriever::retrieve() -> void {
  Values::get_instance().mode =
      RROSACE::FlightMode::Mode(__sp_attribute_->getValue<int>());
}

template <>
auto Retriever::create<ModeRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ModeRetriever>(sp_objects_map,
                                            up_instances_subscribed_map));
}

AltitudeRefRetriever::AltitudeRefRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(ALTITUDE_REF, REFERENCE, REFERENCE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto AltitudeRefRetriever::retrieve() -> void {
  Values::get_instance().h_c = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<AltitudeRefRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class AltitudeRefRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

VerticalSpeedRefRetriever::VerticalSpeedRefRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(VERTICAL_SPEED_REF, REFERENCE, REFERENCE_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto VerticalSpeedRefRetriever::retrieve() -> void {
  Values::get_instance().vz_c = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<VerticalSpeedRefRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class VerticalSpeedRefRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

TrueAirspeedRefRetriever::TrueAirspeedRefRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(TRUE_AIRSPEED_REF, REFERENCE, REFERENCE_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto TrueAirspeedRefRetriever::retrieve() -> void {
  Values::get_instance().va_c = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<TrueAirspeedRefRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class TrueAirspeedRefRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ThrottleCommandRetriever::ThrottleCommandRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(THROTTLE_COMMAND, CONTROL_COMMAND, CONTROL_COMMAND_INSTANCE,
                sp_objects_map, up_instances_subscribed_map) {}

auto ThrottleCommandRetriever::retrieve() -> void {
  Values::get_instance().delta_th_c = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<ThrottleCommandRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrottleCommandRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ElevatorDeflectionCommandRetriever::ElevatorDeflectionCommandRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(ELEVATOR_DEFLECTION_COMMAND, CONTROL_COMMAND,
                CONTROL_COMMAND_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

auto ElevatorDeflectionCommandRetriever::retrieve() -> void {
  Values::get_instance().delta_e_c = __sp_attribute_->getValue<double>();
}

template <>
auto Retriever::create<ElevatorDeflectionCommandRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionCommandRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ThrottleCommandPartialRetriever::ThrottleCommandPartialRetriever(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(THROTTLE_COMMAND_PARTIAL, CONTROL_COMMAND_PARTIAL,
                CONTROL_COMMAND_PARTIAL_INSTANCE + std::to_string(index),
                sp_objects_map, up_instances_subscribed_map),
      __index_(index) {}

auto ThrottleCommandPartialRetriever::retrieve() -> void {
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
auto Retriever::create<ThrottleCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrottleCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
auto Retriever::create<ThrottleCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrottleCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}

RelayThrottleCommandPartialRetriever::RelayThrottleCommandPartialRetriever(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(RELAY_THROTTLE_COMMAND, RELAY_CONTROL_COMMAND,
                RELAY_CONTROL_COMMAND_INSTANCE + std::to_string(index),
                sp_objects_map, up_instances_subscribed_map),
      __index_(index) {}

auto RelayThrottleCommandPartialRetriever::retrieve() -> void {
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
auto Retriever::create<RelayThrottleCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayThrottleCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
auto Retriever::create<RelayThrottleCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayThrottleCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}

ElevatorDeflectionCommandPartialRetriever::
    ElevatorDeflectionCommandPartialRetriever(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(ELEVATOR_DEFLECTION_COMMAND_PARTIAL, CONTROL_COMMAND_PARTIAL,
                CONTROL_COMMAND_PARTIAL_INSTANCE + std::to_string(index),
                sp_objects_map, up_instances_subscribed_map),
      __index_(index) {}

auto ElevatorDeflectionCommandPartialRetriever::retrieve() -> void {
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
auto Retriever::create<ElevatorDeflectionCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
auto Retriever::create<ElevatorDeflectionCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}

RelayElevatorDeflectionCommandPartialRetriever::
    RelayElevatorDeflectionCommandPartialRetriever(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(RELAY_ELEVATOR_DEFLECTION_COMMAND, RELAY_CONTROL_COMMAND,
                RELAY_CONTROL_COMMAND_INSTANCE + std::to_string(index),
                sp_objects_map, up_instances_subscribed_map),
      __index_(index) {}

auto RelayElevatorDeflectionCommandPartialRetriever::retrieve() -> void {
  switch (__index_) {
  case 1:
    Values::get_instance().relay_delta_e_c_1 =
        __sp_attribute_->getValue<bool>()
            ? RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED
            : RROSACE::Cables::RelayState ::RROSACE_RELAY_CLOSED;
    break;
  case 2:
    Values::get_instance().relay_delta_e_c_2 =
        __sp_attribute_->getValue<bool>()
            ? RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED
            : RROSACE::Cables::RelayState ::RROSACE_RELAY_CLOSED;
    break;
  default:
    break;
  }
}

template <>
auto Retriever::create<RelayElevatorDeflectionCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
auto Retriever::create<RelayElevatorDeflectionCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    -> UpRetriever {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}
