#pragma once



#include <allegro_flare/objects/sound_object.h>
#include <map>



class AudioController
{
private:
   Sound *current_music_track;
   std::map<std::string, Sound> sounds;
   std::map<std::string, Sound> music;

public:
   AudioController(std::vector<std::string> sound_filenames, std::vector<std::string> music_filenames);
   ~AudioController();

   void stop_all();

   void play_music(std::string filename, bool loop=true);
   void play_sound_effect(std::string filename);
};



