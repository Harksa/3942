#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager() {
	Mix_CloseAudio();
}

bool SoundManager::load(std::string fileName, std::string id, sound_type type) {
	if(type == SOUND_MUSIC) {
		Mix_Music * music = Mix_LoadMUS(fileName.c_str());
		if(music == nullptr) {
			std::cout << "Could not load music : ERROR - " << Mix_GetError() << std::endl;
			return false;
		}

		_musics[id] = music;
		return true;
	} else if(type == SOUND_SFX) {
		Mix_Chunk * chunck = Mix_LoadWAV(fileName.c_str());
		if(chunck == nullptr) {
			std::cout << "Couldn't load SFX : ERROR - " << Mix_GetError() << std::endl;
			return false;
		}

		_sfxs[id] = chunck;
		return true;
	}

	return false;
}

void SoundManager::playMusic(std::string id, int loop) {
	Mix_PlayMusic(_musics[id], loop);
}

void SoundManager::playSound(std::string id, int loop) {
	Mix_PlayChannel(-1, _sfxs[id], loop);
}

