//! \file IBinder.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values binder interface

#ifndef RROSACE_SEAPLANES_IBINDER_H
#define RROSACE_SEAPLANES_IBINDER_H

#include <string>

class IBinder {
protected:
  static const std::string AIRCRAFT;
  static const std::string AIRCRAFT_INSTANCE;
  static const std::string TRUE_AIRSPEED;
  static const std::string VERTICAL_ACCELERATION;
  static const std::string PITCH_RATE;
  static const std::string VERTICAL_SPEED;
  static const std::string ALTITUDE;

  static const std::string CONTROL_COMMAND;
  static const std::string CONTROL_COMMAND_INSTANCE;
  static const std::string ELEVATOR_DEFLECTION_COMMAND;
  static const std::string THROTTLE_COMMAND;

  static const std::string CONTROL_COMMAND_PARTIAL;
  static const std::string CONTROL_COMMAND_PARTIAL_INSTANCE;
  static const std::string ELEVATOR_DEFLECTION_COMMAND_PARTIAL;
  static const std::string THROTTLE_COMMAND_PARTIAL;

  static const std::string ENGINE;
  static const std::string ENGINE_INSTANCE;
  static const std::string ENGINE_THRUST;

  static const std::string ELEVATOR;
  static const std::string ELEVATOR_INSTANCE;
  static const std::string ELEVATOR_DEFLECTION;

  static const std::string FILTERS;
  static const std::string FILTERS_INSTANCE;
  static const std::string FILTERED_TRUE_AIRSPEED;
  static const std::string FILTERED_VERTICAL_ACCELERATION;

  static const std::string FILTERED_PITCH_RATE;
  static const std::string FILTERED_VERTICAL_SPEED;
  static const std::string FILTERED_ALTITUDE;

  static const std::string FLIGHT_MODE;
  static const std::string FLIGHT_MODE_INSTANCE;
  static const std::string MODE;

  static const std::string REFERENCE;
  static const std::string REFERENCE_INSTANCE;
  static const std::string TRUE_AIRSPEED_REF;
  static const std::string VERTICAL_SPEED_REF;
  static const std::string ALTITUDE_REF;

  static const std::string RELAY_CONTROL_COMMAND;
  static const std::string RELAY_CONTROL_COMMAND_INSTANCE;
  static const std::string RELAY_ELEVATOR_DEFLECTION_COMMAND;
  static const std::string RELAY_THROTTLE_COMMAND;

public:
  virtual ~IBinder() = default;
  virtual void sync() = 0;
};

#endif // RROSACE_SEAPLANES_IBINDER_H
