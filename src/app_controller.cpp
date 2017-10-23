


#include <dr_runner/app_controller.h>

#include <allegro_flare/framework.h>
#include <dr_runner/emitters/user_event_emitter.h>
#include <dr_runner/screens/title_screen.h>
#include <dr_runner/app_events.h>



AppController::AppController(Display *d)
   : Screen(d)
   , current_screen(nullptr)
{
   UserEventEmitter::emit_event(START_TITLE_SCREEN_EVENT);
}



AppController::~AppController()
{
}



void AppController::user_event_func()
{
   const ALLEGRO_EVENT *event = Framework::current_event;

   switch (event->user.type)
   {
   case START_TITLE_SCREEN_EVENT:
      current_screen.reset(new TitleScreen{
            display,
            "Dr. Runner",
            {
               { "start", START_GAME_PLAY_SCREEN_EVENT },
               { "exit",  QUIT_GAME_EVENT }
            }
         });
      break;
   case QUIT_GAME_EVENT:
      Framework::shutdown_program = true;
      break;
   default:
      std::cout << "An unknown user event was triggered" << std::endl;
      break;
   }
}



