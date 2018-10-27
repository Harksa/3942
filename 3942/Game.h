#pragma once
#include <SDL2/SDL.h>
#include "GameStateMachine.h"
#include "SoundManager.h"

/**
 * \brief Le jeu ainsi que les éléments permettant à son fonctionnement.
 */
class Game {
public:
	/**
	 * \brief Retourne l'instance de Game.
	 */
	static Game* Instance();

	/**
	 * \brief Initialise la fenêtre du jeu.
	 * \param title Le titre de la fenêtre
	 * \param xpos La position en X de la fenêtre
	 * \param ypos La position en Y de la fenêtre
	 * \param width La largeur de la fenêtre
	 * \param height La hauteur de la fenêtre
	 * \param fullscreen booléen déterminant si le jeu est en plein écran ou non.
	 * \return vrai si la fenêtre est correctement initialisé, faux sinon.
	 */
	bool init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen);

	/**
	 * \brief Affiche les éléments du jeu.
	 */
	void render() const;

	/**
	 * \brief Mets à jour les éléments du jeu.
	 */
	void update() const;

	/**
	 * \brief Prends en charge la saisie d'inputs du joueur.
	 */
	void handleEvents() const;

	/**
	 * \brief Nettoie les éléments SDL du jeu.
	 */
	void clean() const;

	/**
	 * \brief Demande de quitter le jeu.
	 */
	void quit();

	/**
	 * \brief Retourne le renderer utilisé.
	 * \return le SDL_Renderer du jeu
	 */
	SDL_Renderer* getRenderer() const;

	/**
	 * \brief Retourne le GameStateMachine utilisé dans le jeu
	 * \return Le GameStateMachine du jeu.
	 */
	GameStateMachine* getStateMachine() const;

	/**
	 * \brief booléen permettant de déterminer si le jeu est en cours d'éxecution ou non.
	 * \return vrai si le jeu est en cours d'éxecution, faux sinon.
	 */
	bool running() const;

private:

	Game() = default;

	/**
	 * \brief Le GameStateMachine du jeu.
	 */
	GameStateMachine * _gameStateMachine{nullptr};

	/**
	 * \brief l'instance de la classe Game.
	 */
	static Game * instance;

	/**
	 * \brief La fenêtre dans laquelle est rendu le jeu.
	 */
	SDL_Window * sdl_window{nullptr};

	/**
	 * \brief Le renderer dans lequelle est rendu le jeu.
	 */
	SDL_Renderer * sdl_renderer{nullptr};

	/**
	 * \brief booléen déterminant si le jeu est en cours d'éxecution ou non.
	 */
	bool _running{false};
};

