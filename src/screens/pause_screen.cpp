


#include <dr_runner/screens/pause_screen.h>

#include <allegro_flare/framework.h>
#include <dr_runner/emitters/user_event_emitter.h>



PauseScreen::PauseScreen(Display *display)
   : Screen(display)
   , audio_controller({}, {})
   , fonts()
   , menu_cursor_pos(0)
   , title(TextObject("Pause"))
   , menu_items()
   , state(DISABLED)
{
}



PauseScreen::~PauseScreen()
{
}



void PauseScreen::primary_timer_func()
{
   al_clear_to_color(color::black);

   // draw the title
   title.draw();

   // draw the menu options
   for (auto &menu_item : menu_items) menu_item.first.draw();
}



void PauseScreen::key_down_func()
{
   if (state == SHOWING_MENU)
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
}



void PauseScreen::cursor_up_action()
{
   menu_cursor_pos--;
   if (menu_cursor_pos < 0) menu_cursor_pos = menu_items.size() - 1;
   refresh_focused_menu_item();
}



void PauseScreen::cursor_down_action()
{
   menu_cursor_pos++;
   if (menu_cursor_pos >= menu_items.size()) menu_cursor_pos = 0;
   refresh_focused_menu_item();
}



void PauseScreen::refresh_focused_menu_item()
{
   for (unsigned i=0; i<menu_items.size(); i++)
   {
      if (i == menu_cursor_pos) menu_items[i].first.scale(1.5, 1.5).color(color::yellow);
      else menu_items[i].first.scale(1.0, 1.0).color(color::gray);
   }
}



void PauseScreen::select_option_action()
{
   state = MENU_ITEM_SELECTED;
   UserEventEmitter::emit_event(menu_items[menu_cursor_pos].second);
}



