//! \file Updaters.cpp
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values updaters implementations

#include <Updaters.h>

Updater::Updater(const Name &attribute_name, const Name &object_name,
                 const Name &instance_name, MapSpObjects &sp_objects_map,
                 MapUpObjectInstancesPublished &up_instances_published_map)
    : __sp_attribute_(Seaplanes::Attribute::create(attribute_name)) {
  const auto search_object = sp_objects_map.find(object_name);
  if (search_object == sp_objects_map.end()) {
    auto &&sp_object = Seaplanes::Object::create(object_name);
    sp_objects_map.insert({object_name, std::move(sp_object)});
  }

  const auto &sp_object = sp_objects_map.at(object_name);

  const auto &search_instance = up_instances_published_map.find(instance_name);

  if (search_instance == up_instances_published_map.end()) {
    auto &&up_instance =
        Seaplanes::ObjectInstancePublished::create(instance_name, sp_object);
    up_instances_published_map.insert({instance_name, std::move(up_instance)});
  }

  const auto &up_instance = up_instances_published_map.at(instance_name);

  up_instance->addAttribute(__sp_attribute_);
}

void Updater::sync() { update(); }

// TODO other updaters

AltitudeUpdater::AltitudeUpdater(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map)
    : Updater(IBinder::ALTITUDE, IBinder::AIRCRAFT, IBinder::AIRCRAFT_INSTANCE,
              sp_objects_map, up_instances_published_map) {}

void AltitudeUpdater::update() {
  __sp_attribute_->setValue<double>(Values::get_instance().h);
}

template <>
UpUpdater Updater::create<AltitudeUpdater>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesPublished &up_instances_published_map) {
  return static_cast<std::unique_ptr<Updater> &&>(
      std::make_unique<class AltitudeUpdater>(sp_objects_map,
                                              up_instances_published_map));
}
