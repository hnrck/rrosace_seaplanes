//! \file Retievers.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values retrievers

#ifndef RROSACE_SEAPLANES_RETRIEVERS_H
#define RROSACE_SEAPLANES_RETRIEVERS_H

#include <Common.h>
#include <IBinder.h>
#include <Values.h>

#include <utility>

using UpRetriever = std::unique_ptr<class Retriever>;
using VecUpRetrievers = std::vector<UpRetriever>;

class Retriever : public IBinder {
protected:
  Seaplanes::SpAttribute __sp_attribute_{nullptr};
  virtual void retrieve() = 0;

public:
  Retriever(const Name &attribute_name, const Name &object_name,
            const Name &instance_name, MapSpObjects &sp_objects_map,
            MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
  virtual ~Retriever() override = default;

  void sync() final;

  template <typename T>
  static UpRetriever
  create(MapSpObjects &sp_objects_map,
         MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

// TODO other retrievers

class AltitudeRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  AltitudeRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

#endif // RROSACE_SEAPLANES_RETRIEVERS_H
