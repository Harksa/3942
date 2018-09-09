#pragma once
#include <iostream>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_audio.h>

/**
 * \brief Type de son
 * Music ou SFX
 */
enum sound_type {
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

/**
 * \brief Gère les sons et musiques du jeu
 */
class SoundManager {
public:
	/**
	 * \brief Retourne l'instance du SoundManager
	 * \return L'instance du SoundManager
	 */
	static SoundManager * Instance() {
		if(instance == nullptr) {
			instance = new SoundManager();
		}

		return instance;
	}

	/**
	 * \brief Charge un fichier son
	 * \param fileName Le fichier son à charger
	 * \param id L'ID du son ou de la musique à charger
	 * \param type Le type de son à charger
	 * \return Vrai si le son a bien été chargé, faux sinon
	 */
	static bool load(const std::string& fileName, const std::string& id, sound_type type);

	/**
	 * \brief Joue le son avec l'ID donnée en paramètre
	 * \param id L'ID du son
	 * \param loop
	 */
	static void playSound(std::string id, int loop = 0);

	/**
	 * \brief Joue la musique avec l'ID donnée en paramètre
	 * \param id L'ID de la musique
	 * \param loop
	 */
	static void playMusic(std::string id, int loop = -1);

	/**
	 * \brief Arrête la musique en cours
	 */
	static void stopMusic();

	/**
	 * \brief Nettoie les sons de la mémoire
	 */
	static void clean();

private:
	/**
	 * \brief L'instance du SoundManager
	 */
	static SoundManager* instance;

	static std::map<std::string, Mix_Chunk*> _sfxs;
	static std::map<std::string, Mix_Music*> _musics;

	SoundManager();
	~SoundManager();
};

