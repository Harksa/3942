#pragma once
#include <SDL2/SDL.h>
#include "GameStateMachine.h"
#include "InputHandler.h"
#include "SoundManager.h"

/**
 * \brief Le jeu ainsi que les �l�ments permettant � son fonctionnement.
 */
class Game {
public:
	/**
	 * \brief Retourne l'instance de Game.
	 */
	static Game * Instance() {
		if(instance == nullptr) {
			instance = new Game();
		}

		return instance;
	}


	/**
	 * \brief Initialise la fen�tre du jeu.
	 * \param title Le titre de la fen�tre
	 * \param xpos La position en X de la fen�tre
	 * \param ypos La position en Y de la fen�tre
	 * \param width La largeur de la fen�tre
	 * \param height La hauteur de la fen�tre
	 * \param fullscreen bool�en d�terminant si le jeu est en plein �cran ou non.
	 * \return vrai si la fen�tre est correctement initialis�, faux sinon.
	 */
	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);

	/**
	 * \brief Affiche les �l�ments du jeu.
	 */
	void render();

	/**
	 * \brief Mets � jour les �l�ments du jeu.
	 */
	void update();

	/**
	 * \brief Prends en charge la saisie d'inputs du joueur.
	 */
	void handleEvents();

	/**
	 * \brief Nettoie les �l�ments SDL du jeu.
	 */
	void clean();

	/**
	 * \brief Demande de quitter le jeu.
	 */
	void quit() { _running = false; }

	/**
	 * \brief Retourne le renderer utilis�.
	 * \return le SDL_Renderer du jeu
	 */
	SDL_Renderer * getRenderer() const {return sdl_renderer;}

	/**
	 * \brief Retourne le GameStateMachine utilis� dans le jeu
	 * \return Le GameStateMachine du jeu.
	 */
	GameStateMachine * getStateMachine() const { return _gameStateMachine;}

	/**
	 * \brief bool�en permettant de d�terminer si le jeu est en cours d'�xecution ou non.
	 * \return vrai si le jeu est en cours d'�xecution, faux sinon.
	 */
	bool running() const { return _running; }

	/**
	 * \brief Retourne la largeur de la fen�tre de jeu.
	 * \return La largeur de la fen�tre de jeu.
	 */
	int getGameWidth() const {return _gameWidth;}

	/**
	 * \brief Retourne la hauteur de la fen�tre de jeu.
	 * \return La hauteur de la fen�tre de jeu.
	 */
	int getGameHeight() const { return _gameHeight; }

private:

	Game();

	/**
	 * \brief La largeur de la fen�tre de jeu.
	 */
	int _gameWidth;

	/**
	 * \brief La hauteur de la fen�tre de jeu.
	 */
	int _gameHeight;

	/**
	 * \brief Le GameStateMachine du jeu.
	 */
	GameStateMachine * _gameStateMachine;


	/**
	 * \brief l'instance de la classe Game.
	 */
	static Game * instance;

	/**
	 * \brief La fen�tre dans laquelle est rendu le jeu.
	 */
	SDL_Window * sdl_window = nullptr;

	/**
	 * \brief Le renderer dans lequelle est rendu le jeu.
	 */
	SDL_Renderer * sdl_renderer = nullptr;

	/**
	 * \brief bool�en d�terminant si le jeu est en cours d'�xecution ou non.
	 */
	bool _running;
};

