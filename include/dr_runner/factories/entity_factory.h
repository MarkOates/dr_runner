#pragma once



#include <dr_runner/models/entities/base.h>
#include <dr_runner/models/entity.h>



class EntityFactory
{
public:
   static std::shared_ptr<Entity::Base> create_entity(Entity::type_t entity_type);
};



