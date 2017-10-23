#pragma once



#include <allegro_flare/objects/text_object.h>
#include <dr_runner/controllers/audio_controller.h>
#include <allegro_flare/screen.h>
#include <string>
#include <vector>



class GamePlayScreen : public Screen
{
private:
   enum
   {
      PLAYING,
      PAUSED,
   };

public:
   AudioController audio_controller;
   FontBin fonts;
   int state;

   GamePlayScreen(Display *display);
   ~GamePlayScreen();

   void primary_timer_func() override;
   void key_down_func() override;
};



