//! \file Common.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Common for RROSACE seaplanes

#ifndef RROSACE_SEAPLANES_COMMON_H
#define RROSACE_SEAPLANES_COMMON_H

#include <map>
#include <string>
#include <vector>

#include <rrosace.h>
#include <seaplanes.h>

using Name = std::string;
using VecNames = std::vector<Name>;

using UpFederate = std::unique_ptr<class Federate>;

using UpModel = std::unique_ptr<RROSACE::Model>;
using VecUpModels = std::vector<UpModel>;

using MapSpObjects = std::map<Name, Seaplanes::SpObject>;

using MapUpObjectInstancesSubscribed =
    std::map<Name, Seaplanes::UpObjectInstanceSubscribed>;

using MapUpObjectInstancesPublished =
    std::map<Name, Seaplanes::UpObjectInstancePublished>;

#endif // RROSACE_SEAPLANES_COMMON_H
