//! \file IBinder.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date January 2020
//! \brief static binder values

#include <IBinder.h>

const std::string IBinder::AIRCRAFT = "Aircraft";
const std::string IBinder::AIRCRAFT_INSTANCE = "AircraftInstance";
const std::string IBinder::TRUE_AIRSPEED = "trueAirspeed";
const std::string IBinder::VERTICAL_ACCELERATION = "verticalAcceleration";
const std::string IBinder::PITCH_RATE = "pitchRate";
const std::string IBinder::VERTICAL_SPEED = "verticalSpeed";
const std::string IBinder::ALTITUDE = "altitude";

const std::string IBinder::CONTROL_COMMAND = "ControlCommand";
const std::string IBinder::CONTROL_COMMAND_INSTANCE = "ControlCommandInstance";
const std::string IBinder::ELEVATOR_DEFLECTION_COMMAND =
    "elevatorDeflectionCommand";
const std::string IBinder::THROTTLE_COMMAND = "throttleCommand";

const std::string IBinder::CONTROL_COMMAND_PARTIAL = "ControlCommandPartial";
const std::string IBinder::CONTROL_COMMAND_PARTIAL_INSTANCE =
    "ControlCommandPartialInstance";
const std::string IBinder::ELEVATOR_DEFLECTION_COMMAND_PARTIAL =
    "elevatorDeflectionCommandPartial";
const std::string IBinder::THROTTLE_COMMAND_PARTIAL = "throttleCommandPartial";

const std::string IBinder::ENGINE = "Engine";
const std::string IBinder::ENGINE_INSTANCE = "EngineInstance";
const std::string IBinder::ENGINE_THRUST = "engineThrust";

const std::string IBinder::ELEVATOR = "Elevator";
const std::string IBinder::ELEVATOR_INSTANCE = "ElevatorInstance";
const std::string IBinder::ELEVATOR_DEFLECTION = "elevatorDeflection";

const std::string IBinder::FILTERS = "Filters";
const std::string IBinder::FILTERS_INSTANCE = "FiltersInstance";
const std::string IBinder::FILTERED_TRUE_AIRSPEED = "filteredTrueAirspeed";
const std::string IBinder::FILTERED_VERTICAL_ACCELERATION =
    "filteredVerticalAcceleration";
const std::string IBinder::FILTERED_PITCH_RATE = "filteredPitchRate";
const std::string IBinder::FILTERED_VERTICAL_SPEED = "filteredVerticalSpeed";
const std::string IBinder::FILTERED_ALTITUDE = "filteredAltitude";

const std::string IBinder::FLIGHT_MODE = "FlightMode";
const std::string IBinder::FLIGHT_MODE_INSTANCE = "FlightModeInstance";
const std::string IBinder::MODE = "mode";

const std::string IBinder::REFERENCE = "Reference";
const std::string IBinder::REFERENCE_INSTANCE = "ReferenceInstance";
const std::string IBinder::TRUE_AIRSPEED_REF = "trueAirspeedRef";
const std::string IBinder::VERTICAL_SPEED_REF = "verticalSpeedRef";
const std::string IBinder::ALTITUDE_REF = "altitudeRef";

const std::string IBinder::RELAY_CONTROL_COMMAND = "RelayControlCommandPartial";
const std::string IBinder::RELAY_CONTROL_COMMAND_INSTANCE =
    "RelayControlCommandPartialInstance";
const std::string IBinder::RELAY_ELEVATOR_DEFLECTION_COMMAND =
    "relayElevatorDeflectionCommandPartial";
const std::string IBinder::RELAY_THROTTLE_COMMAND =
    "relayThrottleCommandPartial";
