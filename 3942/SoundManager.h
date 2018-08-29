#pragma once
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_audio.h>


enum sound_type {
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

class SoundManager {
public:
	static SoundManager * Instance() {
		if(instance == nullptr) {
			instance = new SoundManager();
		}

		return instance;
	}

	bool load(std::string fileName, std::string id, sound_type type);

	void playSound(std::string id, int loop);
	void playMusic(std::string id, int loop);

private:
	static SoundManager* instance;

	std::map<std::string, Mix_Chunk*> _sfxs;
	std::map<std::string, Mix_Music*> _musics;

	SoundManager();
	~SoundManager();

	SoundManager(const SoundManager&);
	SoundManager &operator(const SoundManager&);
};

