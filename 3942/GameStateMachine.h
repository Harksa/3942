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
	/**
	 * \brief Créer un état
	 * \param pChoice Le choix de l'état à créer
	 */
	void createState(StateChoice pChoice);

	/**
	 * \brief Rajoute un état par dessus un état existant. (sans suppression)
	 * \param pChoice Le nouvel état où l'on souhaiter aller.
	 */
	void pushState(StateChoice pChoice);

	/**
	 * \brief Change l'état pour celui rentré en paramètre.
	 * \param pChoice Le nouvel état où l'on souhaiter aller.
	 */
	void changeState(StateChoice pChoice);

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
	std::vector<std::shared_ptr<GameState>> game_states;
};

