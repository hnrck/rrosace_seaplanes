//! \file Updaters.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values updaters

#ifndef RROSACE_SEAPLANES_UPDATERS_H
#define RROSACE_SEAPLANES_UPDATERS_H

#include <Common.h>
#include <IBinder.h>
#include <Values.h>

#include <utility>

using UpUpdater = std::unique_ptr<class Updater>;
using VecUpUpdaters = std::vector<UpUpdater>;

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

  template <typename T>
  static UpUpdater
  create(MapSpObjects &sp_objects_map,
         MapUpObjectInstancesPublished &up_instances_published_map);
};

// TODO other updaters

class AltitudeUpdater final : public Updater {
protected:
  void update() final;

public:
  AltitudeUpdater(MapSpObjects &sp_objects_map,
                  MapUpObjectInstancesPublished &up_instances_published_map);
};

#endif // RROSACE_SEAPLANES_UPDATERS_H
