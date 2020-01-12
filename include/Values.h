//! \file Values.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief RROSACE values for seaplanes

#ifndef RROSACE_SEAPLANES_VALUES_H
#define RROSACE_SEAPLANES_VALUES_H

#include <Retrievers.h>
#include <Updaters.h>

#include <array>

#include <rrosace.h>

static constexpr const double H_C = RROSACE::H_EQ;
static constexpr const double VZ_C = 2.5;
static constexpr const double VA_C = RROSACE::VA_EQ;

struct Values final {
  RROSACE::FlightMode::Mode mode{RROSACE::FlightMode::Mode::RROSACE_COMMANDED};
  double delta_e{RROSACE::DELTA_E_EQ};
  double delta_e_c_partial_1{RROSACE::DELTA_E_C_EQ};
  double delta_e_c_partial_2{RROSACE::DELTA_E_C_EQ};
  double delta_th_c_partial_1{RROSACE::DELTA_TH_C_EQ};
  double delta_th_c_partial_2{RROSACE::DELTA_TH_C_EQ};
  RROSACE::Cables::RelayState relay_delta_e_c_1{
      RROSACE::Cables::RelayState::RROSACE_RELAY_CLOSED};
  RROSACE::Cables::RelayState relay_delta_e_c_2{
      RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED};
  RROSACE::Cables::RelayState relay_delta_th_c_1{
      RROSACE::Cables::RelayState::RROSACE_RELAY_CLOSED};
  RROSACE::Cables::RelayState relay_delta_th_c_2{
      RROSACE::Cables::RelayState::RROSACE_RELAY_OPENED};
  double delta_e_c{RROSACE::DELTA_E_C_EQ};
  double delta_th_c{RROSACE::DELTA_TH_C_EQ};
  double t{RROSACE::T_EQ};
  double h{RROSACE::H_EQ};
  double vz{RROSACE::VZ_EQ};
  double va{RROSACE::VA_EQ};
  double q{RROSACE::Q_EQ};
  double az{RROSACE::AZ_EQ};
  double h_f{RROSACE::H_F_EQ};
  double vz_f{RROSACE::VZ_F_EQ};
  double va_f{RROSACE::VA_F_EQ};
  double q_f{RROSACE::Q_F_EQ};
  double az_f{RROSACE::AZ_F_EQ};
  RROSACE::FlightControlComputer::MasterInLaw master_in_law_1{
      RROSACE::FlightControlComputer::MasterInLaw::RROSACE_MASTER_IN_LAW};
  RROSACE::FlightControlComputer::MasterInLaw master_in_law_2{
      RROSACE::FlightControlComputer::MasterInLaw::RROSACE_NOT_MASTER_IN_LAW};
  RROSACE::FlightControlComputer::MasterInLaw other_master_in_law_1{
      RROSACE::FlightControlComputer::MasterInLaw::RROSACE_NOT_MASTER_IN_LAW};
  RROSACE::FlightControlComputer::MasterInLaw other_master_in_law_2{
      RROSACE::FlightControlComputer::MasterInLaw::RROSACE_MASTER_IN_LAW};
  double h_c{H_C};
  double vz_c{VZ_C};
  double va_c{VA_C};

  struct Status final {
    enum State : uint8_t {
      IGNORED = 0,
      PUBLISH = 1,
      SUBSCRIBE = 2,
      LOCAL = 3,
    } state;

    union state_flags {
      State state{IGNORED};
      struct Flags {
        uint8_t produced : 1;
        uint8_t consumed : 1;
      } flags;
    } sf;

    auto set_produced_flag() -> void;
    auto set_consumed_flag() -> void;
  };

  Status mode_status{};
  Status delta_e_status{};
  Status delta_e_c_partial_1_status{};
  Status delta_e_c_partial_2_status{};
  Status delta_th_c_partial_1_status{};
  Status delta_th_c_partial_2_status{};
  Status relay_delta_e_c_1_status{};
  Status relay_delta_e_c_2_status{};
  Status relay_delta_th_c_1_status{};
  Status relay_delta_th_c_2_status{};
  Status delta_e_c_status{};
  Status delta_th_c_status{};
  Status t_status{};
  Status h_status{};
  Status vz_status{};
  Status va_status{};
  Status q_status{};
  Status az_status{};
  Status h_f_status{};
  Status vz_f_status{};
  Status va_f_status{};
  Status q_f_status{};
  Status az_f_status{};
  Status master_in_law_1_status{};
  Status master_in_law_2_status{};
  Status other_master_in_law_1_status{};
  Status other_master_in_law_2_status{};
  Status h_c_status{};
  Status vz_c_status{};
  Status va_c_status{};

  using StatusCreatorsTuple =
      std::tuple<Values::Status &, updaterCreator, retrieverCreator>;
  using StatusCreatorsTuplesArray = std::array<StatusCreatorsTuple, 26>;

  StatusCreatorsTuplesArray status_creators_tuples_array;

  struct Output final {
    enum OutputType : uint8_t {
      INT = 0,
      DOUBLE = 1,
      BOOL = 2,
    } output_type;
    void *p_value;
    Name name;
    Name abbreviation;
    Name dimension;

    auto legend() const -> std::string;
    auto to_string() const -> std::string;
  };

  using StatusOutputTuple = std::tuple<Values::Status &, Output>;
  using StatusOutputTuplesArray = std::array<StatusOutputTuple, 26>;

  StatusOutputTuplesArray status_output_tuples_array;

  ~Values() = default;

  Values(const Values &) = delete;
  auto operator=(const Values &) = delete;

  Values(Values &&) = default;
  auto operator=(Values &&) -> Values & = default;

  static auto get_instance() -> Values &;

  auto legend() const -> std::string;
  auto header_line() const -> std::string;
  auto to_string(double time) const -> std::string;

private:
  Values();
};

#endif // RROSACE_SEAPLANES_VALUES_H
