#pragma once



#include <allegro_flare/objects/text_object.h>
#include <dr_runner/controllers/audio_controller.h>
#include <allegro_flare/screen.h>
#include <string>
#include <vector>



class TitleScreen : public Screen
{
private:
   enum
   {
      SHOWING_TITLE,
      ITEM_SELECTED
   };

public:
   AudioController audio_controller;
   FontBin fonts;
   int menu_cursor_pos;
   TextObject title;
   std::vector<std::pair<TextObject, int32_t>> menu_items;
   int state;

   TitleScreen(Display *display, std::string game_title, std::vector<std::pair<std::string, int32_t>> menu_items);

   void primary_timer_func() override;
   void key_down_func() override;

   void cursor_up_action();
   void cursor_down_action();
   void select_option_action();

   void refresh_focused_menu_item();
};



