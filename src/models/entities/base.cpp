


#include <dr_runner/models/entities/base.h>



Entity::Base::Base(Entity::type_t type, std::shared_ptr<SpriteSheet> sprite_sheet)
   : type(type)
   , state(0)
   , sprite_sheet(sprite_sheet)
   , bitmap(nullptr)
   , placement()
   , velocity(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
{
}



Entity::Base::~Base()
{
}



void Entity::Base::update(float speed)
{
   placement2d scaled_velocity(velocity * speed);
   placement += scaled_velocity;
}



void Entity::Base::draw()
{
   placement.start_transform();
   al_draw_bitmap(bitmap, 0, 0, 0);
   placement.restore_transform();
}



void Entity::Base::set_state(Entity::state_t new_state)
{
   state = new_state;
}



Entity::state_t Entity::Base::get_state()
{
   return state;
}



