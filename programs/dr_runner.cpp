


#include <allegro_flare/allegro_flare.h>

#include <dr_runner/app_controller.h>



int main(int argc, char **argv)
{
   Framework::initialize();
   Config config = Framework::get_config();
   Display *display = Framework::create_display(
         config.get_or_default_int("GLOBAL_SETTINGS", "resolution_x", 1280),
         config.get_or_default_int("GLOBAL_SETTINGS", "resolution_y", 720),
         ALLEGRO_OPENGL | ALLEGRO_PROGRAMMABLE_PIPELINE
      );
   AppController app_controller(display);
   Framework::run_loop();

   return 0;
}



