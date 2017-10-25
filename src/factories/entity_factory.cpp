


#include <dr_runner/factories/entity_factory.h>



EntityFactory::EntityFactory(std::shared_ptr<SpriteSheet> sprite_sheet)
   : sprite_sheet(sprite_sheet)
{
}



EntityFactory::~EntityFactory()
{
}



std::shared_ptr<Entity::Base> EntityFactory::create_entity(Entity::type_t entity_type)
{
   std::shared_ptr<Entity::Base> entity(nullptr);

   if (entity_type == "base")
   {
      entity = std::shared_ptr<Entity::Base>{new Entity::Base("base", sprite_sheet)};
   }

   return entity;
}



