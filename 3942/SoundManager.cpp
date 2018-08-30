#include "SoundManager.h"

SoundManager * SoundManager::instance = nullptr;

SoundManager::SoundManager() {
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager() {
	Mix_CloseAudio();
}

bool SoundManager::load(const std::string& fileName, const std::string& id, const sound_type type) {
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

void SoundManager::stopMusic() const {
	Mix_HaltMusic();
}


void SoundManager::playSound(std::string id, int loop) {
	Mix_PlayChannel(-1, _sfxs[id], loop);
}

void SoundManager::clean() {
	for (auto& _music : _musics) {
		Mix_FreeMusic(_music.second);
	}

	_musics.clear();

	for (auto& _sfx : _sfxs) {
		Mix_FreeChunk(_sfx.second);
	}

	_sfxs.clear();

	Mix_CloseAudio();
}