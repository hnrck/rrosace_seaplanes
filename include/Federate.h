//! \file Federate.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Federate

#ifndef RROSACE_SEAPLANES_FEDERATE_H
#define RROSACE_SEAPLANES_FEDERATE_H

#include <ProtoLogicalProcessor.h>

class Federate final : Seaplanes::ProtoLogicalProcessor {
public:
  void localsCalculation() final;
  void initDumpFiles() final;
  void dumpValuesInFiles() final;
};

#endif // RROSACE_SEAPLANES_FEDERATE_H
