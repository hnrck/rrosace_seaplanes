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
  const std::string AIRCRAFT{"Aircraft"};
  const std::string AIRCRAFT_INSTANCE{"AircraftInstance"};
  const std::string TRUE_AIRSPEED{"trueAirspeed"};
  const std::string VERTICAL_ACCELERATION{"verticalAcceleration"};
  const std::string PITCH_RATE{"pitchRate"};
  const std::string VERTICAL_SPEED{"verticalSpeed"};
  const std::string ALTITUDE{"altitude"};

  const std::string CONTROL_COMMAND{"ControlCommand"};
  const std::string CONTROL_COMMAND_INSTANCE{"ControlCommandInstance"};
  const std::string ELEVATOR_DEFLECTION_COMMAND{"elevatorDeflectionCommand"};
  const std::string THROTTLE_COMMAND{"throttleCommand"};

  const std::string CONTROL_COMMAND_PARTIAL{"ControlCommandPartial"};
  const std::string CONTROL_COMMAND_PARTIAL_INSTANCE{
      "ControlCommandPartialInstance"};
  const std::string ELEVATOR_DEFLECTION_COMMAND_PARTIAL{
      "elevatorDeflectionCommandPartial"};
  const std::string THROTTLE_COMMAND_PARTIAL{"throttleCommandPartial"};

  const std::string ENGINE{"Engine"};
  const std::string ENGINE_INSTANCE{"EngineInstance"};
  const std::string ENGINE_THRUST{"engineThrust"};

  const std::string ELEVATOR{"Elevator"};
  const std::string ELEVATOR_INSTANCE{"ElevatorInstance"};
  const std::string ELEVATOR_DEFLECTION{"elevatorDeflection"};

  const std::string FILTERS{"Filters"};
  const std::string FILTERS_INSTANCE{"FiltersInstance"};
  const std::string FILTERED_TRUE_AIRSPEED{"filteredTrueAirspeed"};
  const std::string FILTERED_VERTICAL_ACCELERATION{
      "filteredVerticalAcceleration"};
  const std::string FILTERED_PITCH_RATE{"filteredPitchRate"};
  const std::string FILTERED_VERTICAL_SPEED{"filteredVerticalSpeed"};
  const std::string FILTERED_ALTITUDE{"filteredAltitude"};

  const std::string FLIGHT_MODE{"FlightMode"};
  const std::string FLIGHT_MODE_INSTANCE{"FlightModeInstance"};
  const std::string MODE{"mode"};

  const std::string REFERENCE{"Reference"};
  const std::string REFERENCE_INSTANCE{"ReferenceInstance"};
  const std::string TRUE_AIRSPEED_REF{"trueAirspeedRef"};
  const std::string VERTICAL_SPEED_REF{"verticalSpeedRef"};
  const std::string ALTITUDE_REF{"altitudeRef"};

  const std::string RELAY_CONTROL_COMMAND{"RelayControlCommandPartial"};
  const std::string RELAY_CONTROL_COMMAND_INSTANCE{
      "RelayControlCommandPartialInstance"};
  const std::string RELAY_ELEVATOR_DEFLECTION_COMMAND{
      "relayElevatorDeflectionCommandPartial"};

public:
  virtual ~IBinder() = default;
  virtual void sync() = 0;
};

#endif // RROSACE_SEAPLANES_IBINDER_H
