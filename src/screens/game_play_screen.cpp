


#include <allegro_flare/framework.h>
#include <dr_runner/screens/game_play_screen.h>
#include <dr_runner/emitters/user_event_emitter.h>
#include <dr_runner/app_events.h>



#define GAME_PLAY_MUSIC "game_play_music.ogg"
#define JUMP_SOUND      "jump_sound.ogg"



GamePlayScreen::GamePlayScreen(Display *display)
   : Screen(display)
   , audio_controller( { JUMP_SOUND }, { GAME_PLAY_MUSIC } )
   , state(PLAYING)
   , entities()
{
   audio_controller.play_music(GAME_PLAY_MUSIC);
}



GamePlayScreen::~GamePlayScreen()
{
}



void GamePlayScreen::primary_timer_func()
{
   al_clear_to_color(color::slategray);
}



void GamePlayScreen::key_down_func()
{
   switch(Framework::current_event->keyboard.keycode)
   {
   case ALLEGRO_KEY_ESCAPE:
      UserEventEmitter::emit_event(START_TITLE_SCREEN_EVENT);
      break;
   }
}



void GamePlayScreen::draw_scene()
{
   for (auto &entity : entities) entity->draw();
}



