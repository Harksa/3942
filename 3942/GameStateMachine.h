#pragma once
#include "GameState.h"
#include <vector>

/**
 * Gére les états du jeu, tel que la transition entre différents états.
 * Un état est équivalent à un écran de jeu ou niveau.
 */
class GameStateMachine {
public:
	/**
	 * \brief Rajoute un état par dessus un état existant. (sans suppression)
	 * \param state Le nouvel état où l'on souhaiter aller.
	 */
	void pushState(GameState * state);

	/**
	 * \brief Change l'état pour celui rentré en paramètre.
	 * \param state Le nouvel état où l'on souhaiter aller.
	 */
	void changeState(GameState *state);

	/**
	 * \brief Détruit le dernier état de la liste.
	 */
	void popState();

	/**
	 * \brief Mets à jour l'état courant.
	 */
	void update();

	/**
	 * \brief Affiche l'état courant.
	 */
	void render();

private:

	/**
	 * \brief La liste des états du jeu.
	 */
	std::vector<GameState *> _gameStates;
};

