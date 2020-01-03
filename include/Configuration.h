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
  virtual const char *what() const noexcept;
};

class Configuration final {
public:
  Configuration();
  Configuration(int argc, char *argv[]);
  ~Configuration() = default;
  Configuration(const Configuration &) = default;
  Configuration &operator=(const Configuration &) = delete;
  Configuration(Configuration &&) = delete;
  Configuration &operator=(Configuration &&) = delete;

  void parse_arguments(int argc, char *argv[]) noexcept(false);
  void print_help(const char exec_name[], std::ostream &stream) const;

  friend std::ostream &operator<<(std::ostream &stream,
                                  const Configuration &configuration);

  Name get_federation() const;
  Name get_fom() const;
  Name get_federate() const;
  bool get_verbose() const;
  std::ostream &get_log() const;
  std::ostream &get_output() const;
  std::vector<Name> get_models() const;

  Seaplanes::SeaplanesTime get_end_time() const;

private:
  Name __federation_;
  Name __fom_;
  Name __federate_;
  bool __verbose_;
  std::ostream &__log_;
  std::ostream &__output_;
  std::vector<Name> __models_;

  Seaplanes::SeaplanesTime __end_time_;

  bool __federation_set_;
  bool __fom_set_;
  bool __federate_set_;

  bool initialized() const;
};

#endif // CONFIGURATION_H
