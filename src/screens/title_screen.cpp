


#include <allegro_flare/framework.h>
#include <dr_runner/screens/title_screen.h>
#include <dr_runner/emitters/user_event_emitter.h>
#include <dr_runner/app_events.h>



#define GAME_SHOW_MUSIC "tada_music.ogg"
#define PUNCH_SOUND     "punch.ogg"



TitleScreen::TitleScreen(Display *display, std::string game_title, std::vector<std::pair<std::string, int32_t>> menu_items)
   : Screen(display)
   , audio_controller( { PUNCH_SOUND }, { GAME_SHOW_MUSIC } )
   , fonts()
   , menu_cursor_pos(0)
   , title(TextObject(game_title))
   , menu_items()
   , state(SHOWING_TITLE)
{
   ALLEGRO_FONT *font = fonts["ChronoTrigger.ttf 60"];

   title.font(font)
      .align(0.5, 1.1)
      .scale(2, 2)
      .position(display->center(), display->middle()-100);

   int count = 0;
   for (auto &menu_item : menu_items)
   {
      this->menu_items.emplace_back(TextObject(menu_item.first), menu_item.second);

      this->menu_items[this->menu_items.size()-1].first.font(font)
         .align(0.5, 0.5)
         .scale(1.0, 1.0)
         .position(display->center(), display->middle()+count*50 + 100);

      count++;
   }

   refresh_focused_menu_item();

   audio_controller.play_music(GAME_SHOW_MUSIC);
}



void TitleScreen::primary_timer_func()
{
   al_clear_to_color(color::black);

   // draw the title
   title.draw();

   // draw the menu options
   for (auto &menu_item : menu_items) menu_item.first.draw();
}



void TitleScreen::key_down_func()
{
   switch(Framework::current_event->keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
      cursor_up_action();
      break;
   case ALLEGRO_KEY_DOWN:
      cursor_down_action();
      break;
   case ALLEGRO_KEY_ENTER:
   case ALLEGRO_KEY_SPACE:
      select_option_action();
      break;
   }
}



void TitleScreen::cursor_up_action()
{
   menu_cursor_pos--;
   if (menu_cursor_pos < 0) menu_cursor_pos = menu_items.size() - 1;
   refresh_focused_menu_item();
}



void TitleScreen::cursor_down_action()
{
   menu_cursor_pos++;
   if (menu_cursor_pos >= menu_items.size()) menu_cursor_pos = 0;
   refresh_focused_menu_item();
}



void TitleScreen::refresh_focused_menu_item()
{
   for (unsigned i=0; i<menu_items.size(); i++)
   {
      if (i == menu_cursor_pos) menu_items[i].first.scale(1.5, 1.5).color(color::yellow);
      else menu_items[i].first.scale(1.0, 1.0).color(color::gray);
   }
}



void TitleScreen::select_option_action()
{
   state = ITEM_SELECTED;
   UserEventEmitter::emit_event(menu_items[menu_cursor_pos].second);
}



