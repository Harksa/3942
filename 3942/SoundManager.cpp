#include <iostream>
#include "SoundManager.h"

std::map<std::string, Mix_Chunk*> SoundManager::sfxs;
std::map<std::string, Mix_Music*> SoundManager::musics;

bool SoundManager::audio_opened{false};

void SoundManager::openAudio() {
	if(!audio_opened) {
		Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
		audio_opened = true;
	}
}

void SoundManager::closeAudio() {
	Mix_CloseAudio();
	audio_opened = false;
}


bool SoundManager::load(const std::string& pFileName, const std::string& pId, const sound_type pType) {
	if(pType == SOUND_MUSIC) {
		Mix_Music * music = Mix_LoadMUS(pFileName.c_str());
		if(music == nullptr) {
			std::cout << "Could not load music : ERROR - " << Mix_GetError() << std::endl;
			return false;
		}

		musics[pId] = music;
		return true;
	} else if(pType == SOUND_SFX) {
		Mix_Chunk * chunck = Mix_LoadWAV(pFileName.c_str());
		if(chunck == nullptr) {
			std::cout << "Couldn't load SFX : ERROR - " << Mix_GetError() << std::endl;
			return false;
		}

		sfxs[pId] = chunck;
		return true;
	}

	return false;
}

void SoundManager::playMusic(const std::string pId, const int pLoop) {
	Mix_PlayMusic(musics[pId], pLoop);
}

void SoundManager::stopMusic() {
	Mix_HaltMusic();
}

void SoundManager::playSound(const std::string pId, const int pLoop) {
	Mix_PlayChannel(-1, sfxs[pId], pLoop);
}

void SoundManager::clean() {
	for(auto itr = musics.begin() ; itr != musics.end() ; ) {
		Mix_FreeMusic(itr->second);
		itr = musics.erase(itr);
	}

	for(auto itr = sfxs.begin() ; itr != sfxs.end() ; ) {
		Mix_FreeChunk(itr->second);
		itr = sfxs.erase(itr);
	}

	musics.clear();

	sfxs.clear();

	Mix_CloseAudio();
}

SoundManager::~SoundManager() {
	clean();
}
