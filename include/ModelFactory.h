//! \file ModelFactory.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Model factory

#ifndef RROSACE_SEAPLANES_MODELFACTORY_H
#define RROSACE_SEAPLANES_MODELFACTORY_H

#include <FederateBuilder.h>

#include <map>

class ModelFactory {
private:
  template <class T, unsigned int instance> static auto generate() -> UpModel;

public:
  ModelFactory() = delete;
  ~ModelFactory() = delete;

  ModelFactory(const ModelFactory &) = delete;
  auto operator=(const ModelFactory &) = delete;

  ModelFactory(ModelFactory &&) = default;
  auto operator=(ModelFactory &&) -> ModelFactory & = default;

  static UpModel generate(const Name &model_name);
};

#endif // RROSACE_SEAPLANES_MODELFACTORY_H
