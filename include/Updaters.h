//! \file Updaters.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values updaters

#ifndef RROSACE_SEAPLANES_UPDATERS_H
#define RROSACE_SEAPLANES_UPDATERS_H

#include <Common.h>
#include <IBinder.h>

#include <utility>

using UpUpdater = std::unique_ptr<class Updater>;
using VecUpUpdaters = std::vector<UpUpdater>;
using updaterCreator = UpUpdater (*)(MapSpObjects &,
                                     MapUpObjectInstancesPublished &);

class Updater : public IBinder {
protected:
  Seaplanes::SpAttribute __sp_attribute_{nullptr};
  virtual void update() = 0;

public:
  Updater(const Name &attribute_name, const Name &object_name,
          const Name &instance_name, MapSpObjects &sp_objects_map,
          MapUpObjectInstancesPublished &up_instances_published_map);
  virtual ~Updater() override = default;

  void sync() final;

  template <typename T, unsigned int instance>
  static UpUpdater
  create(MapSpObjects &sp_objects_map,
         MapUpObjectInstancesPublished &up_instances_published_map);
};

class ThrustUpdater final : public Updater {
protected:
  void update() final;

public:
  ThrustUpdater(MapSpObjects &sp_objects_map,
                MapUpObjectInstancesPublished &up_instances_published_map);
};

class ElevatorDeflectionUpdater final : public Updater {
protected:
  void update() final;

public:
  ElevatorDeflectionUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class AltitudeUpdater final : public Updater {
protected:
  void update() final;

public:
  AltitudeUpdater(MapSpObjects &sp_objects_map,
                  MapUpObjectInstancesPublished &up_instances_published_map);
};

class VerticalSpeedUpdater final : public Updater {
protected:
  void update() final;

public:
  VerticalSpeedUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class TrueAirspeedUpdater final : public Updater {
protected:
  void update() final;

public:
  TrueAirspeedUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class PitchRateUpdater final : public Updater {
protected:
  void update() final;

public:
  PitchRateUpdater(MapSpObjects &sp_objects_map,
                   MapUpObjectInstancesPublished &up_instances_published_map);
};

class VerticalAccelerationUpdater final : public Updater {
protected:
  void update() final;

public:
  VerticalAccelerationUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class FilteredAltitudeUpdater final : public Updater {
protected:
  void update() final;

public:
  FilteredAltitudeUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class FilteredVerticalSpeedUpdater final : public Updater {
protected:
  void update() final;

public:
  FilteredVerticalSpeedUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class FilteredTrueAirspeedUpdater final : public Updater {
protected:
  void update() final;

public:
  FilteredTrueAirspeedUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class FilteredPitchRateUpdater final : public Updater {
protected:
  void update() final;

public:
  FilteredPitchRateUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class FilteredVerticalAccelerationUpdater final : public Updater {
protected:
  void update() final;

public:
  FilteredVerticalAccelerationUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class ModeUpdater final : public Updater {
protected:
  void update() final;

public:
  ModeUpdater(MapSpObjects &sp_objects_map,
              MapUpObjectInstancesPublished &up_instances_published_map);
};

class AltitudeRefUpdater final : public Updater {
protected:
  void update() final;

public:
  AltitudeRefUpdater(MapSpObjects &sp_objects_map,
                     MapUpObjectInstancesPublished &up_instances_published_map);
};

class VerticalSpeedRefUpdater final : public Updater {
protected:
  void update() final;

public:
  VerticalSpeedRefUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class TrueAirspeedRefUpdater final : public Updater {
protected:
  void update() final;

public:
  TrueAirspeedRefUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class ThrottleCommandUpdater final : public Updater {
protected:
  void update() final;

public:
  ThrottleCommandUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class ElevatorDeflectionCommandUpdater final : public Updater {
protected:
  void update() final;

public:
  ElevatorDeflectionCommandUpdater(
      MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class ThrottleCommandPartialUpdater final : public Updater {
private:
  unsigned int __index_;

protected:
  void update() final;

public:
  ThrottleCommandPartialUpdater(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class RelayThrottleCommandPartialUpdater final : public Updater {
private:
  unsigned int __index_;

protected:
  void update() final;

public:
  RelayThrottleCommandPartialUpdater(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class ElevatorDeflectionCommandPartialUpdater final : public Updater {
private:
  unsigned int __index_;

protected:
  void update() final;

public:
  ElevatorDeflectionCommandPartialUpdater(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

class RelayElevatorDeflectionCommandPartialUpdater final : public Updater {
private:
  unsigned int __index_;

protected:
  void update() final;

public:
  RelayElevatorDeflectionCommandPartialUpdater(
      unsigned int index, MapSpObjects &sp_objects_map,
      MapUpObjectInstancesPublished &up_instances_published_map);
};

#endif // RROSACE_SEAPLANES_UPDATERS_H
