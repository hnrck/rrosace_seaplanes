//! \file Retrievers.h
//! \author Henrick Deschamps
//! \version 1.0.0
//! \date December 2019
//! \brief Values retrievers implementations

#include <Retrievers.h>

Retriever::Retriever(
    const Name &attribute_name, const Name &object_name,
    const Name &instance_name, MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : __sp_attribute_(Seaplanes::Attribute::create(attribute_name)) {
  const auto search_object = sp_objects_map.find(object_name);
  if (search_object == sp_objects_map.end()) {
    auto &&sp_object = Seaplanes::Object::create(object_name);
    sp_objects_map.insert({object_name, std::move(sp_object)});
  }

  const auto &sp_object = sp_objects_map.at(object_name);

  const auto &search_instance = up_instances_subscribed_map.find(instance_name);

  if (search_instance == up_instances_subscribed_map.end()) {
    auto &&up_instance =
        Seaplanes::ObjectInstanceSubscribed::create(instance_name, sp_object);
    up_instances_subscribed_map.insert({instance_name, std::move(up_instance)});
  }

  const auto &up_instance = up_instances_subscribed_map.at(instance_name);

  up_instance->addAttribute(__sp_attribute_);
}

void Retriever::sync() { retrieve(); }

// TODO other retrievers

AltitudeRetriever::AltitudeRetriever(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map)
    : Retriever(IBinder::ALTITUDE, IBinder::AIRCRAFT,
                IBinder::AIRCRAFT_INSTANCE, sp_objects_map,
                up_instances_subscribed_map) {}

void AltitudeRetriever::retrieve() {
  Values::get_instance().h = __sp_attribute_->getValue<double>();
}

template <>
UpRetriever Retriever::create<AltitudeRetriever>(
    MapSpObjects &sp_objects_map,
    MapUpObjectInstancesSubscribed &up_instances_subscribed_map) {
  return static_cast<std::unique_ptr<Retriever> &&>(
      std::make_unique<class AltitudeRetriever>(sp_objects_map,
                                                up_instances_subscribed_map));
}
