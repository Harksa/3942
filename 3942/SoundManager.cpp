#include <iostream>
#include "SoundManager.h"

std::map<std::string, Mix_Chunk*> SoundManager::sfxs;
std::map<std::string, Mix_Music*> SoundManager::musics;
bool SoundManager::is_music_enabled = true;

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
		if(musics.find(pId) == musics.end()) {
			Mix_Music * music = Mix_LoadMUS(pFileName.c_str());
			if(music == nullptr) {
				std::cout << "SOUNDMANAGER::LOAD:: " << Mix_GetError() << std::endl;
				return false;
			}

			musics[pId] = music;
		}
		return true;
	} 
	
	if(pType == SOUND_SFX) {
		if(sfxs.find(pId) == sfxs.end()) {
			Mix_Chunk * chunck = Mix_LoadWAV(pFileName.c_str());
			if(chunck == nullptr) {
				std::cout << "SOUNDMANAGER::LOAD:: " << Mix_GetError() << std::endl;
				return false;
			}

			sfxs[pId] = chunck;
		}
		return true;
	}

	return false;
}

void SoundManager::setMusicVolume(unsigned int pNewVolume) {
	if(pNewVolume > 100)
		pNewVolume = 100;

	Mix_VolumeMusic(pNewVolume * 100 / MIX_MAX_VOLUME);
}

void SoundManager::playMusic(const std::string& pId, const int pLoop) {
	if(is_music_enabled) {
		if(Mix_PlayMusic(musics[pId], pLoop) == -1) {
			std::cout << "ERROR::SOUNDMANAGER::PLAY MUSIC : " << Mix_GetError() << std::endl;
		}
	}
}

void SoundManager::stopMusic() {
	Mix_HaltMusic();
}

void SoundManager::playSound(const std::string& pId, const int pLoop) {
	if(Mix_PlayChannel(-1, sfxs[pId], pLoop) == -1) {
		std::cout << "ERROR::SOUNDMANAGER::PLAY SOUND : " << Mix_GetError() << std::endl;
	}
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
