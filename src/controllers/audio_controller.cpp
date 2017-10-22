


#include <dr_runner/controllers/audio_controller.h>

#include <allegro_flare/framework.h>



AudioController::AudioController(std::vector<std::string> sound_filenames, std::vector<std::string> music_filenames)
   : current_music_track(nullptr)
   , sounds()
   , music()
{
   for (auto &filename : sound_filenames) sounds.emplace(filename, Sound(Framework::sample(filename)));
   for (auto &filename : music_filenames) music.emplace(filename, Sound(Framework::sample(filename)));
}



AudioController::~AudioController()
{
   stop_all();
}



void AudioController::stop_all()
{
   for (auto &sound : sounds) sound.second.stop();
   for (auto &music_ : music) music_.second.stop();
}



void AudioController::play_music(std::string filename, bool loop)
{
   decltype(sounds)::iterator it = sounds.find(filename);

   if (it == sounds.end()) return;

   Sound &found_sound = (*it).second;

   if (&found_sound == current_music_track) return;

   stop_all();

   current_music_track = &found_sound;

   // set the loop setting on the Sound object
   found_sound.loop(loop);

   // play track
   found_sound.play();
}



void AudioController::play_sound_effect(std::string filename)
{
   std::map<std::string, Sound>::iterator it = sounds.find(filename);
   if (it == sounds.end()) return;
   Sound &found_sound = (*it).second;
   found_sound.play();
}



