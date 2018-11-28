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
 * \brief G�re les sons et musiques du jeu
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
	 * \param pFileName Le fichier son � charger
	 * \param pId L'ID du son ou de la musique � charger
	 * \param pType Le type de son � charger
	 * \return Vrai si le son a bien �t� charg�, faux sinon
	 */
	static bool load(const std::string& pFileName, const std::string& pId, sound_type pType);

	/**
	 * \brief D�finie le volume de la musique.
	 * \param pNewVolume Le nouveau volume de la musique. D�finie entre 0 et 100
	 */
	static void setMusicVolume(unsigned int pNewVolume);

	/**
	 * \brief Joue le son avec l'ID donn�e en param�tre
	 * \param pId L'ID du son
	 * \param pLoop
	 */
	static void playSound(const std::string& pId, int pLoop = 0);

	/**
	 * \brief Joue la musique avec l'ID donn�e en param�tre
	 * \param pId L'ID de la musique
	 * \param pLoop
	 */
	static void playMusic(const std::string& pId, int pLoop = -1);

	/**
	 * \brief Arr�te la musique en cours
	 */
	static void stopMusic();

	/**
	 * \brief Nettoie les sons de la m�moire
	 */
	static void clean();

	~SoundManager();

private:

	/**
	 * \brief Bool�en permettant de d�finir si l'audio a d�j� �t� initialis� ou non.
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
	 * \brief D�termine si la musique est activ� ou non.
	 */
	static bool is_music_enabled;
};

