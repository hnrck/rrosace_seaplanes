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

void Retriever::sync() { retrieve(); }

ThrustRetriever::ThrustRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ENGINE_THRUST, IBinder::ENGINE,
                IBinder::ENGINE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void ThrustRetriever::retrieve() {
  Values::get_instance().t = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<ThrustRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrustRetriever>(sp_objects_map,
                                              up_instances_subscribed_map));
}

ElevatorDeflectionRetriever::ElevatorDeflectionRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ELEVATOR_DEFLECTION, IBinder::ELEVATOR,
                IBinder::ELEVATOR_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void ElevatorDeflectionRetriever::retrieve() {
  Values::get_instance().delta_e = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<ElevatorDeflectionRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

AltitudeRetriever::AltitudeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ALTITUDE, IBinder::AIRCRAFT,
                IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void AltitudeRetriever::retrieve() {
  Values::get_instance().h = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<AltitudeRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class AltitudeRetriever>(sp_objects_map,
                                                up_instances_subscribed_map));
}

VerticalSpeedRetriever::VerticalSpeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::VERTICAL_SPEED, IBinder::AIRCRAFT,
                IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void VerticalSpeedRetriever::retrieve() {
  Values::get_instance().vz = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<VerticalSpeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class VerticalSpeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

TrueAirspeedRetriever::TrueAirspeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::TRUE_AIRSPEED, IBinder::AIRCRAFT,
                IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void TrueAirspeedRetriever::retrieve() {
  Values::get_instance().va = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<TrueAirspeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class TrueAirspeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

PitchRateRetriever::PitchRateRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::PITCH_RATE, IBinder::AIRCRAFT,
                IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void PitchRateRetriever::retrieve() {
  Values::get_instance().q = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<PitchRateRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class PitchRateRetriever>(sp_objects_map,
                                                 up_instances_subscribed_map));
}

VerticalAccelerationRetriever::VerticalAccelerationRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::VERTICAL_ACCELERATION, IBinder::AIRCRAFT,
                IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void VerticalAccelerationRetriever::retrieve() {
  Values::get_instance().az = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<VerticalAccelerationRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class VerticalAccelerationRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredAltitudeRetriever::FilteredAltitudeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::FILTERED_ALTITUDE, IBinder::FILTERS,
                IBinder::FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void FilteredAltitudeRetriever::retrieve() {
  Values::get_instance().h_f = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<FilteredAltitudeRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredAltitudeRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredVerticalSpeedRetriever::FilteredVerticalSpeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::FILTERED_VERTICAL_SPEED, IBinder::FILTERS,
                IBinder::FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void FilteredVerticalSpeedRetriever::retrieve() {
  Values::get_instance().vz_f = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<FilteredVerticalSpeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredVerticalSpeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredTrueAirspeedRetriever::FilteredTrueAirspeedRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::FILTERED_TRUE_AIRSPEED, IBinder::FILTERS,
                IBinder::FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void FilteredTrueAirspeedRetriever::retrieve() {
  Values::get_instance().va_f = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<FilteredTrueAirspeedRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredTrueAirspeedRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredPitchRateRetriever::FilteredPitchRateRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::FILTERED_PITCH_RATE, IBinder::FILTERS,
                IBinder::FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void FilteredPitchRateRetriever::retrieve() {
  Values::get_instance().q_f = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<FilteredPitchRateRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredPitchRateRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

FilteredVerticalAccelerationRetriever::FilteredVerticalAccelerationRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::FILTERED_VERTICAL_ACCELERATION, IBinder::FILTERS,
                IBinder::FILTERS_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void FilteredVerticalAccelerationRetriever::retrieve() {
  Values::get_instance().az_f = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<FilteredVerticalAccelerationRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class FilteredVerticalAccelerationRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ModeRetriever::ModeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::MODE, IBinder::FLIGHT_MODE,
                IBinder::FLIGHT_MODE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void ModeRetriever::retrieve() {
  Values::get_instance().mode =
      RROSACE::FlightMode::Mode(__sp_attribute_->getValue<int>());
}

template <>
UpRetriever Retriever::create<ModeRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ModeRetriever>(sp_objects_map,
                                            up_instances_subscribed_map));
}

AltitudeRefRetriever::AltitudeRefRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ALTITUDE_REF, IBinder::REFERENCE,
                IBinder::REFERENCE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void AltitudeRefRetriever::retrieve() {
  Values::get_instance().h_c = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<AltitudeRefRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class AltitudeRefRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

VerticalSpeedRefRetriever::VerticalSpeedRefRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::VERTICAL_SPEED_REF, IBinder::REFERENCE,
                IBinder::REFERENCE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void VerticalSpeedRefRetriever::retrieve() {
  Values::get_instance().vz_c = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<VerticalSpeedRefRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class VerticalSpeedRefRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

TrueAirspeedRefRetriever::TrueAirspeedRefRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::TRUE_AIRSPEED_REF, IBinder::REFERENCE,
                IBinder::REFERENCE_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void TrueAirspeedRefRetriever::retrieve() {
  Values::get_instance().va_c = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<TrueAirspeedRefRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class TrueAirspeedRefRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ThrottleCommandRetriever::ThrottleCommandRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::THROTTLE_COMMAND, IBinder::CONTROL_COMMAND,
                IBinder::CONTROL_COMMAND_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void ThrottleCommandRetriever::retrieve() {
  Values::get_instance().delta_th_c = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<ThrottleCommandRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrottleCommandRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ElevatorDeflectionCommandRetriever::ElevatorDeflectionCommandRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ELEVATOR_DEFLECTION_COMMAND, IBinder::CONTROL_COMMAND,
                IBinder::CONTROL_COMMAND_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void ElevatorDeflectionCommandRetriever::retrieve() {
  Values::get_instance().delta_e_c = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<ElevatorDeflectionCommandRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionCommandRetriever>(
          sp_objects_map, up_instances_subscribed_map));
}

ThrottleCommandPartialRetriever::ThrottleCommandPartialRetriever(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::THROTTLE_COMMAND_PARTIAL + std::to_string(index),
                IBinder::CONTROL_COMMAND_PARTIAL,
                IBinder::CONTROL_COMMAND_PARTIAL_INSTANCE, sp_objects_map,
                up_instances_subscribed_map),
      __index_(index) {}

void ThrottleCommandPartialRetriever::retrieve() {
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
UpRetriever Retriever::create<ThrottleCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrottleCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
UpRetriever Retriever::create<ThrottleCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ThrottleCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}

RelayThrottleCommandPartialRetriever::RelayThrottleCommandPartialRetriever(
    unsigned int index, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::RELAY_THROTTLE_COMMAND + std::to_string(index),
                IBinder::RELAY_CONTROL_COMMAND,
                IBinder::RELAY_CONTROL_COMMAND_INSTANCE, sp_objects_map,
                up_instances_subscribed_map),
      __index_(index) {}

void RelayThrottleCommandPartialRetriever::retrieve() {
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
UpRetriever Retriever::create<RelayThrottleCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayThrottleCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
UpRetriever Retriever::create<RelayThrottleCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayThrottleCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}

ElevatorDeflectionCommandPartialRetriever::
    ElevatorDeflectionCommandPartialRetriever(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ELEVATOR_DEFLECTION_COMMAND_PARTIAL +
                    std::to_string(index),
                IBinder::CONTROL_COMMAND_PARTIAL,
                IBinder::CONTROL_COMMAND_PARTIAL_INSTANCE, sp_objects_map,
                up_instances_subscribed_map),
      __index_(index) {}

void ElevatorDeflectionCommandPartialRetriever::retrieve() {
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
UpRetriever Retriever::create<ElevatorDeflectionCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
UpRetriever Retriever::create<ElevatorDeflectionCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class ElevatorDeflectionCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}

RelayElevatorDeflectionCommandPartialRetriever::
    RelayElevatorDeflectionCommandPartialRetriever(
        unsigned int index, MapSpObjects &sp_objects_map,
        MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::RELAY_ELEVATOR_DEFLECTION_COMMAND +
                    std::to_string(index),
                IBinder::RELAY_CONTROL_COMMAND,
                IBinder::RELAY_CONTROL_COMMAND_INSTANCE, sp_objects_map,
                up_instances_subscribed_map),
      __index_(index) {}

void RelayElevatorDeflectionCommandPartialRetriever::retrieve() {
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
UpRetriever
Retriever::create<RelayElevatorDeflectionCommandPartialRetriever, 1>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialRetriever>(
          1, sp_objects_map, up_instances_subscribed_map));
}

template <>
UpRetriever
Retriever::create<RelayElevatorDeflectionCommandPartialRetriever, 2>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class RelayElevatorDeflectionCommandPartialRetriever>(
          2, sp_objects_map, up_instances_subscribed_map));
}
