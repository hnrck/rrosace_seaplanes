//! \file Values.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief RROSACE values for seaplanes

#ifndef RROSACE_SEAPLANES_VALUES_H
#define RROSACE_SEAPLANES_VALUES_H

#include <FederateBuilder.h>
#include <rrosace.h>

#define H_C (RROSACE::H_EQ)
#define VZ_C (2.5)
#define VA_C (RROSACE::VA_EQ)

struct Values final {
private:
  Values() = default;

public:
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
    enum {
      IGNORED = 0,
      PUBLISH = 1,
      SUBSCRIBE = 2,
      LOCAL = 3,
    };
    union {
      uint8_t state;
      struct {
        uint8_t publish : 1;
        uint8_t subscribe : 1;
      };
    };
  };

  Status mode_status{Status::IGNORED};
  Status delta_e_status{Status::IGNORED};
  Status delta_e_c_partial_1_status{Status::IGNORED};
  Status delta_e_c_partial_2_status{Status::IGNORED};
  Status delta_th_c_partial_1_status{Status::IGNORED};
  Status delta_th_c_partial_2_status{Status::IGNORED};
  Status relay_delta_e_c_1_status{Status::IGNORED};
  Status relay_delta_e_c_2_status{Status::IGNORED};
  Status relay_delta_th_c_1_status{Status::IGNORED};
  Status relay_delta_th_c_2_status{Status::IGNORED};
  Status delta_e_c_status{Status::IGNORED};
  Status delta_th_c_status{Status::IGNORED};
  Status t_status{Status::IGNORED};
  Status h_status{Status::IGNORED};
  Status vz_status{Status::IGNORED};
  Status va_status{Status::IGNORED};
  Status q_status{Status::IGNORED};
  Status az_status{Status::IGNORED};
  Status h_f_status{Status::IGNORED};
  Status vz_f_status{Status::IGNORED};
  Status va_f_status{Status::IGNORED};
  Status q_f_status{Status::IGNORED};
  Status az_f_status{Status::IGNORED};
  Status master_in_law_1_status{Status::IGNORED};
  Status master_in_law_2_status{Status::IGNORED};
  Status other_master_in_law_1_status{Status::IGNORED};
  Status other_master_in_law_2_status{Status::IGNORED};
  Status h_c_status{Status::IGNORED};
  Status vz_c_status{Status::IGNORED};
  Status va_c_status{Status::IGNORED};

  Values(const Values &) = delete;
  Values &operator=(const Values &) = delete;
  Values(Values &&) = default;
  Values &operator=(Values &&) = default;

  static Values &get_instance() {
    static auto &&values = Values();
    return values;
  }
};

#endif // RROSACE_SEAPLANES_VALUES_H
