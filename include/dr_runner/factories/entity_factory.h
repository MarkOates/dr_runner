#pragma once



#include <dr_runner/models/entities/base.h>



class EntityFactory
{
private:
   std::shared_ptr<SpriteSheet> sprite_sheet;

public:
   EntityFactory(std::shared_ptr<SpriteSheet> sprite_sheet=nullptr);
   ~EntityFactory();

   std::shared_ptr<Entity::Base> create_entity(Entity::type_t entity_type);
};



