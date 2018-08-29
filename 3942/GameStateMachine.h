#pragma once
#include "GameState.h"
#include <vector>

/**
 * G�re les �tats du jeu, tel que la transition entre diff�rents �tats.
 * Un �tat est �quivalent � un �cran de jeu ou niveau.
 */
class GameStateMachine {
public:
	/**
	 * \brief Rajoute un �tat par dessus un �tat existant. (sans suppression)
	 * \param state Le nouvel �tat o� l'on souhaiter aller.
	 */
	void pushState(GameState * state);

	/**
	 * \brief Change l'�tat pour celui rentr� en param�tre.
	 * \param state Le nouvel �tat o� l'on souhaiter aller.
	 */
	void changeState(GameState *state);

	/**
	 * \brief D�truit le dernier �tat de la liste.
	 */
	void popState();

	/**
	 * \brief Mets � jour l'�tat courant.
	 */
	void update();

	/**
	 * \brief Affiche l'�tat courant.
	 */
	void render();

private:

	/**
	 * \brief La liste des �tats du jeu.
	 */
	std::vector<GameState *> _gameStates;
};

