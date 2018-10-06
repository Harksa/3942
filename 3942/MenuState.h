#pragma once
#include <vector>
#include "GameState.h"
#include "MenuButton.h"

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
	virtual void setCallbacks(const std::vector<Callback>& callbacks) {
		for (auto& _gameObject : _gameObjects) {
			if(dynamic_cast<MenuButton*>(_gameObject)) {
				auto button = dynamic_cast<MenuButton*>(_gameObject);
				button->setCallback(callbacks[button->getCallbackID()]);
			}
		}
	}


	/**
	 * \brief La liste des fonctions.
	 */
	std::vector<Callback> _callbacks;
};

