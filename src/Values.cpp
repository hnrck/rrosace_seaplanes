//! \file Values.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief RROSACE values for seaplanes

#include <Values.h>

using std::get;
using std::string;

Values::Values()
    : status_creators_tuples_array{{{mode_status,
                                     Updater::create<ModeUpdater, 1>,
                                     Retriever::create<ModeRetriever, 1>},
                                    {delta_e_status,
                                     Updater::create<ElevatorDeflectionUpdater,
                                                     1>,
                                     Retriever::create<
                                         ElevatorDeflectionRetriever, 1>},
                                    {delta_e_c_partial_1_status,
                                     Updater::create<
                                         ElevatorDeflectionCommandPartialUpdater,
                                         1>,
                                     Retriever::create<
                                         ElevatorDeflectionCommandPartialRetriever,
                                         1>},
                                    {delta_e_c_partial_2_status,
                                     Updater::create<
                                         ElevatorDeflectionCommandPartialUpdater,
                                         2>,
                                     Retriever::create<
                                         ElevatorDeflectionCommandPartialRetriever,
                                         2>},
                                    {delta_th_c_partial_1_status,
                                     Updater::create<
                                         ThrottleCommandPartialUpdater, 1>,
                                     Retriever::create<
                                         ThrottleCommandPartialRetriever, 1>},
                                    {delta_th_c_partial_2_status,
                                     Updater::create<
                                         ThrottleCommandPartialUpdater, 2>,
                                     Retriever::create<
                                         ThrottleCommandPartialRetriever, 2>},
                                    {relay_delta_e_c_1_status,
                                     Updater::create<
                                         RelayElevatorDeflectionCommandPartialUpdater,
                                         1>,
                                     Retriever::create<
                                         RelayElevatorDeflectionCommandPartialRetriever,
                                         1>},
                                    {relay_delta_e_c_2_status,
                                     Updater::create<
                                         RelayElevatorDeflectionCommandPartialUpdater,
                                         2>,
                                     Retriever::create<
                                         RelayElevatorDeflectionCommandPartialRetriever,
                                         2>},
                                    {relay_delta_th_c_1_status,
                                     Updater::create<
                                         RelayThrottleCommandPartialUpdater, 1>,
                                     Retriever::create<
                                         RelayThrottleCommandPartialRetriever,
                                         1>},
                                    {relay_delta_th_c_2_status,
                                     Updater::create<
                                         RelayThrottleCommandPartialUpdater, 2>,
                                     Retriever::create<
                                         RelayThrottleCommandPartialRetriever,
                                         2>},
                                    {delta_e_c_status,
                                     Updater::create<
                                         ElevatorDeflectionCommandUpdater, 1>,
                                     Retriever::create<
                                         ElevatorDeflectionCommandRetriever,
                                         1>},
                                    {delta_th_c_status,
                                     Updater::create<ThrottleCommandUpdater, 1>,
                                     Retriever::create<ThrottleCommandRetriever,
                                                       1>},
                                    {t_status,
                                     Updater::create<ThrustUpdater, 1>,
                                     Retriever::create<ThrustRetriever, 1>},
                                    {h_status,
                                     Updater::create<AltitudeUpdater, 1>,
                                     Retriever::create<AltitudeRetriever, 1>},
                                    {vz_status,
                                     Updater::create<VerticalSpeedUpdater, 1>,
                                     Retriever::create<VerticalSpeedRetriever,
                                                       1>},
                                    {va_status,
                                     Updater::create<
                                         VerticalAccelerationUpdater, 1>,
                                     Retriever::create<
                                         VerticalAccelerationRetriever, 1>},
                                    {q_status,
                                     Updater::create<PitchRateUpdater, 1>,
                                     Retriever::create<PitchRateRetriever, 1>},
                                    {az_status,
                                     Updater::create<
                                         VerticalAccelerationUpdater, 1>,
                                     Retriever::create<
                                         VerticalAccelerationRetriever, 1>},
                                    {h_f_status,
                                     Updater::create<FilteredAltitudeUpdater,
                                                     1>,
                                     Retriever::create<
                                         FilteredAltitudeRetriever, 1>},
                                    {vz_f_status,
                                     Updater::create<
                                         FilteredVerticalSpeedUpdater, 1>,
                                     Retriever::create<
                                         FilteredVerticalSpeedRetriever, 1>},
                                    {va_f_status,
                                     Updater::create<
                                         FilteredTrueAirspeedUpdater, 1>,
                                     Retriever::create<
                                         FilteredTrueAirspeedRetriever, 1>},
                                    {q_f_status,
                                     Updater::create<FilteredPitchRateUpdater,
                                                     1>,
                                     Retriever::create<
                                         FilteredPitchRateRetriever, 1>},
                                    {az_f_status,
                                     Updater::create<
                                         FilteredVerticalAccelerationUpdater,
                                         1>,
                                     Retriever::create<
                                         FilteredVerticalAccelerationRetriever,
                                         1>},
                                    {h_c_status,
                                     Updater::create<AltitudeRefUpdater, 1>,
                                     Retriever::create<AltitudeRefRetriever,
                                                       1>},
                                    {vz_c_status,
                                     Updater::create<VerticalSpeedRefUpdater,
                                                     1>,
                                     Retriever::create<
                                         VerticalSpeedRefRetriever, 1>},
                                    {va_c_status,
                                     Updater::create<TrueAirspeedRefUpdater, 1>,
                                     Retriever::create<TrueAirspeedRefRetriever,
                                                       1>}}},
      status_output_tuples_array{
          {{mode_status,
            {Output::INT, &mode, "flight mode", "mode", "enumeration"}},
           {delta_e_status,
            {Output::DOUBLE, &delta_e, "delta elevator", "delta_e", "rad/s"}},
           {delta_e_c_partial_1_status,
            {Output::DOUBLE, &delta_e_c_partial_1,
             "delta elevator command partial 1", "delta_e_c_partial_1",
             "rad/s"}},
           {delta_e_c_partial_2_status,
            {Output::DOUBLE, &delta_e_c_partial_2,
             "delta elevator command partial 2", "delta_e_c_partial_2",
             "rad/s"}},
           {delta_th_c_partial_1_status,
            {Output::DOUBLE, &delta_th_c_partial_1,
             "delta throttle command partial 1", "delta_th_c_partial_1",
             "N/s"}},
           {delta_th_c_partial_2_status,
            {Output::DOUBLE, &delta_th_c_partial_2,
             "delta throttle command partial 2", "delta_th_c_partial_2",
             "N/s"}},
           {relay_delta_e_c_1_status,
            {Output::BOOL, &relay_delta_e_c_1,
             "relay delta elevator command partial 1",
             "relay_delta_e_c_partial_1", "bool"}},
           {relay_delta_e_c_2_status,
            {Output::BOOL, &relay_delta_e_c_2,
             "relay delta elevator command partial 2",
             "relay_delta_e_c_partial_2", "bool"}},
           {relay_delta_th_c_1_status,
            {Output::BOOL, &relay_delta_th_c_1,
             "relay delta throttle command partial 1",
             "relay_delta_th_c_partial_1", "bool"}},
           {relay_delta_th_c_2_status,
            {Output::BOOL, &relay_delta_th_c_2,
             "relay delta throttle command partial 2",
             "relay_delta_th_c_partial_2", "bool"}},
           {delta_e_c_status,
            {Output::DOUBLE, &delta_e_c, "delta elevator command", "delta_e_c",
             "rad/s"}},
           {delta_th_c_status,
            {Output::DOUBLE, &delta_th_c, "delta throttle command",
             "delta_th_c", "N/s"}},
           {t_status, {Output::DOUBLE, &t, "thrust", "T", "N"}},
           {h_status, {Output::DOUBLE, &h, "altitude", "h", "m"}},
           {vz_status, {Output::DOUBLE, &vz, "vertical airspeed", "vz", "m/s"}},
           {va_status, {Output::DOUBLE, &va, "true airspeed", "va", "m/s"}},
           {q_status, {Output::DOUBLE, &q, "pitch rate", "q", "rad/s"}},
           {az_status,
            {Output::DOUBLE, &az, "vertical acceleration", "va_z", "m/s^2"}},
           {h_f_status,
            {Output::DOUBLE, &h_f, "altitude filtered", "h_f", "m/s"}},
           {vz_f_status,
            {Output::DOUBLE, &vz_f, "vertical airspeed filtered", "vz_f",
             "m/s"}},
           {va_f_status,
            {Output::DOUBLE, &va_f, "true airspeed filtered", "va_f", "m/s"}},
           {q_f_status,
            {Output::DOUBLE, &q_f, "pitch rate filtered", "q_f", "rad/s"}},
           {az_f_status,
            {Output::DOUBLE, &az_f, "vertical acceleration filtered", "va_z_f",
             "m/s^2"}},
           {h_c_status, {Output::DOUBLE, &h_c, "altitude ref", "h_c", "m"}},
           {vz_c_status,
            {Output::DOUBLE, &vz_c, "vertical airspeed ref", "vz_c", "m/s"}},
           {va_c_status,
            {Output::DOUBLE, &va_c, "true airspeed ref", "va_c", "m/s"}}}} {}

auto Values::Status::set_produced_flag() -> void { sf.flags.produced = 1; }
auto Values::Status::set_consumed_flag() -> void { sf.flags.consumed = 1; }

auto Values::Output::legend() const -> string {
  return "# " + abbreviation + ", " + name + ", " + dimension;
}

auto Values::Output::to_string() const -> string {
  auto str = string();
  switch (output_type) {
  case INT:
    str = std::to_string(*static_cast<int *>(p_value));
    break;
  case DOUBLE:
    str = std::to_string(*static_cast<double *>(p_value));
    break;
  case BOOL:
    str = std::to_string(*static_cast<bool *>(p_value));
    break;
  }
  return str;
}

auto Values::get_instance() -> Values & {
  static auto &&values = Values();
  return values;
}

auto Values::legend() const -> string {
  auto str = string();
  for (auto &status_output_tuple : status_output_tuples_array) {
    auto &status = get<0>(status_output_tuple);
    auto &output = get<1>(status_output_tuple);
    if (status.sf.flags.produced) {
      str += output.legend();
    }
  }
  return str;
}

auto Values::header_line() const -> string {
  auto str = string("# t, ");
  auto delimiter = string();
  for (auto &status_output_tuple : status_output_tuples_array) {
    auto &status = get<0>(status_output_tuple);
    auto &output = get<1>(status_output_tuple);
    if (status.sf.flags.produced) {
      str += delimiter + output.abbreviation;
    }
    delimiter = ", ";
  }
  return str;
}

auto Values::to_string(double time) const -> string {
  auto str = string("# " + std::to_string(time) + ", ");
  auto delimiter = string();
  for (auto &status_output_tuple : status_output_tuples_array) {
    auto &status = get<0>(status_output_tuple);
    auto &output = get<1>(status_output_tuple);
    if (status.sf.flags.produced) {
      str += delimiter + output.to_string();
    }
    delimiter = ", ";
  }
  return str;
}
