#pragma once



#include <allegro_flare/screen.h>



class AppController : public Screen
{
private:
   std::unique_ptr<Screen> current_screen;

public:
   AppController(Display *d);
   ~AppController();

   void user_event_func() override;
};



