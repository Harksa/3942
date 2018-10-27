#pragma once
#include <vector>
#include "GameState.h"
#include "StateChangeAsker.h"

/**
 * Gére les états du jeu, tel que la transition entre différents états.
 * Un état est équivalent à un écran de jeu ou niveau.
 */
class GameStateMachine {
public:
	void createState(StateChoice choice);
	/**
	 * \brief Rajoute un état par dessus un état existant. (sans suppression)
	 * \param choice Le nouvel état où l'on souhaiter aller.
	 */
	void pushState(StateChoice choice);

	/**
	 * \brief Change l'état pour celui rentré en paramètre.
	 * \param choice Le nouvel état où l'on souhaiter aller.
	 */
	void changeState(StateChoice choice);

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

	GameStateMachine() = default;

	~GameStateMachine();

private:

	/**
	 * \brief La liste des états du jeu.
	 */
	std::vector<std::shared_ptr<GameState>> _gameStates;
};

