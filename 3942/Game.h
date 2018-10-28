#pragma once
#include <SDL2/SDL.h>
#include "GameStateMachine.h"
#include "SoundManager.h"

/**
 * \brief Le jeu ainsi que les �l�ments permettant � son fonctionnement.
 */
class Game {
public:
	/**
	 * \brief Retourne l'instance de Game.
	 */
	static Game* Instance();

	/**
	 * \brief Initialise la fen�tre du jeu.
	 * \param pTitle Le titre de la fen�tre
	 * \param pXpos La position en X de la fen�tre
	 * \param pYpos La position en Y de la fen�tre
	 * \param pWidth La largeur de la fen�tre
	 * \param pHeight La hauteur de la fen�tre
	 * \param pFullscreen bool�en d�terminant si le jeu est en plein �cran ou non.
	 * \return vrai si la fen�tre est correctement initialis�, faux sinon.
	 */
	bool init(const char * pTitle, int pXpos, int pYpos, int pWidth, int pHeight, bool pFullscreen);

	/**
	 * \brief Affiche les �l�ments du jeu.
	 */
	void render() const;

	/**
	 * \brief Mets � jour les �l�ments du jeu.
	 */
	void update() const;

	/**
	 * \brief Prends en charge la saisie d'inputs du joueur.
	 */
	void handleEvents() const;

	/**
	 * \brief Nettoie les �l�ments SDL du jeu.
	 */
	void clean() const;

	/**
	 * \brief Demande de quitter le jeu.
	 */
	void quit();

	/**
	 * \brief Retourne le renderer utilis�.
	 * \return le SDL_Renderer du jeu
	 */
	SDL_Renderer* getRenderer() const;

	/**
	 * \brief Retourne le GameStateMachine utilis� dans le jeu
	 * \return Le GameStateMachine du jeu.
	 */
	GameStateMachine* getStateMachine() const;

	/**
	 * \brief bool�en permettant de d�terminer si le jeu est en cours d'�xecution ou non.
	 * \return vrai si le jeu est en cours d'�xecution, faux sinon.
	 */
	bool isRunning() const;

private:

	Game() = default;

	/**
	 * \brief Le GameStateMachine du jeu.
	 */
	GameStateMachine * game_state_machine{nullptr};

	/**
	 * \brief l'instance de la classe Game.
	 */
	static Game * instance;

	/**
	 * \brief La fen�tre dans laquelle est rendu le jeu.
	 */
	SDL_Window * sdl_window{nullptr};

	/**
	 * \brief Le renderer dans lequelle est rendu le jeu.
	 */
	SDL_Renderer * sdl_renderer{nullptr};

	/**
	 * \brief bool�en d�terminant si le jeu est en cours d'�xecution ou non.
	 */
	bool running{false};
};

