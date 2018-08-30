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
 * \brief G�re les sons et musiques du jeu
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
	 * \param fileName Le fichier son � charger
	 * \param id L'ID du son ou de la musique � charger
	 * \param type Le type de son � charger
	 * \return Vrai si le son a bien �t� charg�, faux sinon
	 */
	bool load(const std::string& fileName, const std::string& id, sound_type type);

	/**
	 * \brief Joue le son avec l'ID donn�e en param�tre
	 * \param id L'ID du son
	 * \param loop
	 */
	void playSound(std::string id, int loop);

	/**
	 * \brief Joue la musique avec l'ID donn�e en param�tre
	 * \param id L'ID de la musique
	 * \param loop
	 */
	void playMusic(std::string id, int loop = -1);

	/**
	 * \brief Arr�te la musique en cours
	 */
	void stopMusic() const;

	/**
	 * \brief Nettoie les sons de la m�moire
	 */
	void clean();

private:
	/**
	 * \brief L'instance du SoundManager
	 */
	static SoundManager* instance;

	std::map<std::string, Mix_Chunk*> _sfxs;
	std::map<std::string, Mix_Music*> _musics;

	SoundManager();
	~SoundManager();
};

