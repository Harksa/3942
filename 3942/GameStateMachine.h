#pragma once
#include <vector>
#include "GameState.h"
#include "StateChangeAsker.h"

/**
 * G�re les �tats du jeu, tel que la transition entre diff�rents �tats.
 * Un �tat est �quivalent � un �cran de jeu ou niveau.
 */
class GameStateMachine {
public:
	/**
	 * \brief Cr�er un �tat
	 * \param pChoice Le choix de l'�tat � cr�er
	 */
	void createState(StateChoice pChoice);

	/**
	 * \brief Rajoute un �tat par dessus un �tat existant. (sans suppression)
	 * \param pChoice Le nouvel �tat o� l'on souhaiter aller.
	 */
	void pushState(StateChoice pChoice);

	/**
	 * \brief Change l'�tat pour celui rentr� en param�tre.
	 * \param pChoice Le nouvel �tat o� l'on souhaiter aller.
	 */
	void changeState(StateChoice pChoice);

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

	GameStateMachine() = default;

	~GameStateMachine();

private:

	/**
	 * \brief La liste des �tats du jeu.
	 */
	std::vector<std::shared_ptr<GameState>> game_states;
};

