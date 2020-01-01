//! \file Retievers.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values retrievers

#ifndef RROSACE_SEAPLANES_RETRIEVERS_H
#define RROSACE_SEAPLANES_RETRIEVERS_H

#include <Common.h>
#include <IBinder.h>

#include <utility>

using UpRetriever = std::unique_ptr<class Retriever>;
using VecUpRetrievers = std::vector<UpRetriever>;
using retrieverCreator = UpRetriever (*)(MapSpObjects &,
                                         MapUpObjectInstancesSubscribed &);

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

  template <typename T, unsigned int instance>
  static UpRetriever
  create(MapSpObjects &sp_objects_map,
         MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ThrustRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  ThrustRetriever(MapSpObjects &sp_objects_map,
                  MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ElevatorDeflectionRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  ElevatorDeflectionRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class AltitudeRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  AltitudeRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class VerticalSpeedRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  VerticalSpeedRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class TrueAirspeedRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  TrueAirspeedRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class PitchRateRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  PitchRateRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class VerticalAccelerationRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  VerticalAccelerationRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class FilteredAltitudeRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  FilteredAltitudeRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class FilteredVerticalSpeedRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  FilteredVerticalSpeedRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class FilteredTrueAirspeedRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  FilteredTrueAirspeedRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class FilteredPitchRateRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  FilteredPitchRateRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class FilteredVerticalAccelerationRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  FilteredVerticalAccelerationRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ModeRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  ModeRetriever(MapSpObjects &sp_objects_map,
                MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class AltitudeRefRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  AltitudeRefRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class VerticalSpeedRefRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  VerticalSpeedRefRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class TrueAirspeedRefRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  TrueAirspeedRefRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ThrottleCommandRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  ThrottleCommandRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ElevatorDeflectionCommandRetriever final : public Retriever {
protected:
  void retrieve() final;

public:
  ElevatorDeflectionCommandRetriever(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ThrottleCommandPartialRetriever final : public Retriever {
private:
  unsigned int __index_;

protected:
  void retrieve() final;

public:
  ThrottleCommandPartialRetriever(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class RelayThrottleCommandPartialRetriever final : public Retriever {
private:
  unsigned int __index_;

protected:
  void retrieve() final;

public:
  RelayThrottleCommandPartialRetriever(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class ElevatorDeflectionCommandPartialRetriever final : public Retriever {
private:
  unsigned int __index_;

protected:
  void retrieve() final;

public:
  ElevatorDeflectionCommandPartialRetriever(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

class RelayElevatorDeflectionCommandPartialRetriever final : public Retriever {
private:
  unsigned int __index_;

protected:
  void retrieve() final;

public:
  RelayElevatorDeflectionCommandPartialRetriever(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesSubscribed &up_instances_subscribed_map);
};

#endif // RROSACE_SEAPLANES_RETRIEVERS_H
