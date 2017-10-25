#pragma once



#include <allegro_flare/screen.h>

#include <allegro_flare/objects/text_object.h>
#include <dr_runner/controllers/audio_controller.h>



class PauseScreen : public Screen
{
private:
   enum state_t
   {
      DISABLED,
      REVEALING,
      SHOWING_MENU,
      MENU_ITEM_SELECTED,
      HIDING
   };
public:
   AudioController audio_controller;
   FontBin fonts;
   int menu_cursor_pos;
   TextObject title;
   std::vector<std::pair<TextObject, int32_t>> menu_items;
   int state;

   PauseScreen(Display *display);
   ~PauseScreen();

   void primary_timer_func() override;
   void key_down_func() override;

   void cursor_up_action();
   void cursor_down_action();
   void select_option_action();

   void refresh_focused_menu_item();
};



