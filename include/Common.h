//! \file Common.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Common for RROSACE seaplanes

#ifndef RROSACE_SEAPLANES_COMMON_H
#define RROSACE_SEAPLANES_COMMON_H

#include <string>
#include <vector>

#include <rrosace.h>

using Name = std::string;

using UpFederate = std::unique_ptr<class Federate>;

using UpModel = std::unique_ptr<RROSACE::Model>;
using VecUpModels = std::vector<UpModel>;

#endif // RROSACE_SEAPLANES_COMMON_H
