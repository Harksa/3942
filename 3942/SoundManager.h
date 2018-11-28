#pragma once
#include <string>
#include <map>
#include <SDL2/SDL_mixer.h>

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
	 * \brief Ouvre le mixer de son
	 */
	static void openAudio();

	/**
	 * \brief Ferme le mixer de son
	 */
	static void closeAudio();

	/**
	 * \brief Charge un fichier son
	 * \param pFileName Le fichier son à charger
	 * \param pId L'ID du son ou de la musique à charger
	 * \param pType Le type de son à charger
	 * \return Vrai si le son a bien été chargé, faux sinon
	 */
	static bool load(const std::string& pFileName, const std::string& pId, sound_type pType);

	/**
	 * \brief Définie le volume de la musique.
	 * \param pNewVolume Le nouveau volume de la musique. Définie entre 0 et 100
	 */
	static void setMusicVolume(unsigned int pNewVolume);

	/**
	 * \brief Joue le son avec l'ID donnée en paramètre
	 * \param pId L'ID du son
	 * \param pLoop
	 */
	static void playSound(const std::string& pId, int pLoop = 0);

	/**
	 * \brief Joue la musique avec l'ID donnée en paramètre
	 * \param pId L'ID de la musique
	 * \param pLoop
	 */
	static void playMusic(const std::string& pId, int pLoop = -1);

	/**
	 * \brief Arrête la musique en cours
	 */
	static void stopMusic();

	/**
	 * \brief Nettoie les sons de la mémoire
	 */
	static void clean();

	~SoundManager();

private:

	/**
	 * \brief Booléen permettant de définir si l'audio a déjà été initialisé ou non.
	 */
	static bool audio_opened;

	/**
	 * \brief Map regroupant la liste des sfxs
	 */
	static std::map<std::string, Mix_Chunk*> sfxs;

	/**
	 * \brief Map regroupant la liste des musiques
	 */
	static std::map<std::string, Mix_Music*> musics;

	/**
	 * \brief Détermine si la musique est activé ou non.
	 */
	static bool is_music_enabled;
};

