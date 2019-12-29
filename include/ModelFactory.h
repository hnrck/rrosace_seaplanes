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
  template <class T, unsigned int instance> static UpModel Generate();

public:
  ModelFactory() = delete;
  static UpModel Generate(const Name &model_name);
};

#endif // RROSACE_SEAPLANES_MODELFACTORY_H
