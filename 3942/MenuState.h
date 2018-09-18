#pragma once
#include "GameState.h"
#include <vector>

/**
 * \brief Désigne un état possédant des boutons de menu.
 */
class MenuState : public GameState {

public:
	MenuState() = default;
	virtual ~MenuState() {
		_callbacks.clear();
	}

protected:
	/**
	 * \brief Fonction qui sera appelé lors de l'appuie sur un bouton.
	 */
	typedef void (*Callback) ();

	/**
	 * \brief Mets en place les callbacks sur les boutons du menu.
	 * \param callbacks La liste des fonctions qui seront associées aux boutons.
	 */
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

	/**
	 * \brief La liste des fonctions.
	 */
	std::vector<Callback> _callbacks;
};

