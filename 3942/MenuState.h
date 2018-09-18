#pragma once
#include "GameState.h"
#include <vector>

/**
 * \brief D�signe un �tat poss�dant des boutons de menu.
 */
class MenuState : public GameState {

public:
	MenuState() = default;
	virtual ~MenuState() {
		_callbacks.clear();
	}

protected:
	/**
	 * \brief Fonction qui sera appel� lors de l'appuie sur un bouton.
	 */
	typedef void (*Callback) ();

	/**
	 * \brief Mets en place les callbacks sur les boutons du menu.
	 * \param callbacks La liste des fonctions qui seront associ�es aux boutons.
	 */
	virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

	/**
	 * \brief La liste des fonctions.
	 */
	std::vector<Callback> _callbacks;
};

