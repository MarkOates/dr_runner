


#include <dr_runner/factories/entity_factory.h>



std::shared_ptr<Entity::Base> EntityFactory::create_entity(Entity::type_t entity_type)
{
   std::shared_ptr<Entity::Base> entity(nullptr);

   if (entity_type == "base")
   {
      entity.reset(new Entity::Base("base"));
   }

   return entity;
}



