//! \file IBinder.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values binder interface

#ifndef RROSACE_SEAPLANES_IBINDER_H
#define RROSACE_SEAPLANES_IBINDER_H

#include <Common.h>

class IBinder {
protected:
  static const Name AIRCRAFT;
  static const Name AIRCRAFT_INSTANCE;
  static const Name TRUE_AIRSPEED;
  static const Name VERTICAL_ACCELERATION;
  static const Name PITCH_RATE;
  static const Name VERTICAL_SPEED;
  static const Name ALTITUDE;

  static const Name CONTROL_COMMAND;
  static const Name CONTROL_COMMAND_INSTANCE;
  static const Name ELEVATOR_DEFLECTION_COMMAND;
  static const Name THROTTLE_COMMAND;

  static const Name CONTROL_COMMAND_PARTIAL;
  static const Name CONTROL_COMMAND_PARTIAL_INSTANCE;
  static const Name ELEVATOR_DEFLECTION_COMMAND_PARTIAL;
  static const Name THROTTLE_COMMAND_PARTIAL;

  static const Name ENGINE;
  static const Name ENGINE_INSTANCE;
  static const Name ENGINE_THRUST;

  static const Name ELEVATOR;
  static const Name ELEVATOR_INSTANCE;
  static const Name ELEVATOR_DEFLECTION;

  static const Name FILTERS;
  static const Name FILTERS_INSTANCE;
  static const Name FILTERED_TRUE_AIRSPEED;
  static const Name FILTERED_VERTICAL_ACCELERATION;

  static const Name FILTERED_PITCH_RATE;
  static const Name FILTERED_VERTICAL_SPEED;
  static const Name FILTERED_ALTITUDE;

  static const Name FLIGHT_MODE;
  static const Name FLIGHT_MODE_INSTANCE;
  static const Name MODE;

  static const Name REFERENCE;
  static const Name REFERENCE_INSTANCE;
  static const Name TRUE_AIRSPEED_REF;
  static const Name VERTICAL_SPEED_REF;
  static const Name ALTITUDE_REF;

  static const Name RELAY_CONTROL_COMMAND;
  static const Name RELAY_CONTROL_COMMAND_INSTANCE;
  static const Name RELAY_ELEVATOR_DEFLECTION_COMMAND;
  static const Name RELAY_THROTTLE_COMMAND;

public:
  IBinder() = default;
  virtual ~IBinder() = default;

  IBinder(const IBinder &) = default;
  auto operator=(const IBinder &) -> IBinder & = default;

  IBinder(IBinder &&) = default;
  auto operator=(IBinder &&) -> IBinder & = default;

  virtual auto sync() -> void = 0;
};

#endif // RROSACE_SEAPLANES_IBINDER_H
