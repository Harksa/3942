#pragma once
#include <vector>
#include "GameState.h"
#include "MenuButton.h"

/**
 * \brief Désigne un état possédant des boutons de menu.
 */
class MenuState : public GameState {

public:
	MenuState() = default;
	virtual ~MenuState();

protected:
	/**
	 * \brief Fonction qui sera appelé lors de l'appuie sur un bouton.
	 */
	typedef void (*Callback) ();

	/**
	 * \brief Mets en place les callbacks sur les boutons du menu.
	 * \param pCallbacks La liste des fonctions qui seront associées aux boutons.
	 */
	virtual void setCallbacks(const std::vector<Callback>& pCallbacks);

	/**
	 * \brief La liste des fonctions.
	 */
	std::vector<Callback> _callbacks;
};

inline void MenuState::setCallbacks(const std::vector<Callback>& pCallbacks) {
	for (auto& _gameObject : game_objects) {
		if (dynamic_cast<MenuButton*>(_gameObject)) {
			auto button = dynamic_cast<MenuButton*>(_gameObject);
			button->setCallback(pCallbacks[button->getCallbackId()]);
		}
	}
}

inline MenuState::~MenuState() {
	_callbacks.clear();
}
