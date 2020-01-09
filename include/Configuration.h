//! \file Configuration.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Configuration parser from CLI for RROSACE seaplanes

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// #include <LogicalProcessorCommon.h>
#include <Common.h>
#include <SeaplanesTime.h>

#include <rrosace.h>

#include <exception>
#include <iostream>

class uninitializedConfiguration final : public std::exception {
public:
  auto what() const noexcept -> const char * override;
};

class Configuration final {
public:
  Configuration();
  explicit Configuration(const VecNames &vec_args);
  ~Configuration() = default;

  Configuration(const Configuration &) = default;
  auto operator=(const Configuration &) = delete;

  Configuration(Configuration &&) = delete;
  auto operator=(Configuration &&) = delete;

  auto parse_arguments(const VecNames &vec_args) noexcept(false) -> void;
  auto print_help(const Name &exec_name, std::ostream &stream) const -> void;

  friend auto operator<<(std::ostream &stream,
                         const Configuration &configuration) -> std::ostream &;

  auto get_federation() const -> Name;
  auto get_fom() const -> Name;
  auto get_federate() const -> Name;
  auto get_verbose() const -> bool;
  auto get_log() const -> std::ostream &;
  auto get_output() const -> std::ostream &;
  auto get_models() const -> std::vector<Name>;

  Seaplanes::SeaplanesTime get_end_time() const;

private:
  Name __federation_{};
  Name __fom_{};
  Name __federate_{};
  bool __verbose_{false};
  std::ostream &__log_{std::clog};
  std::ostream &__output_{std::cout};
  std::vector<Name> __models_{};

  Seaplanes::SeaplanesTime __end_time_;

  bool __federation_set_{false};
  bool __fom_set_{false};
  bool __federate_set_{false};

  auto initialized() const -> bool;
};

#endif // CONFIGURATION_H
