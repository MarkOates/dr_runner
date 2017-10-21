#pragma once



#include <allegro5/allegro_image.h>
#include <allegro_flare/placement2d.h>
#include <dr_runner/models/entity.h>
#include <string>



namespace Entity
{
   class Base
   {
   public:
      Entity::type_t type;
      Entity::state_t state;
      ALLEGRO_BITMAP *bitmap;
      placement2d placement;
      placement2d velocity;

      Base(Entity::type_t type);
      virtual ~Base();

      virtual void update(float speed=1.0);
      virtual void draw();
      virtual void set_state(Entity::state_t new_state);
      Entity::state_t get_state();
   };
};


