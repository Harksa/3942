#pragma once
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief Boutton de menu. Le joueur peut cliquer dessus et une action sera effectu� en fonction du callback associ�.
 */
class MenuButton : public SDLGameObject {
public:
	 MenuButton();

	/**
	 * \brief Charge le MenuButton avec les param�tres du LoadParameter
	 * \param parameters Le LoadParameters contenant les informations du MenuButton
	 */
	void load(const LoadParameters *parameters);

	/**
	 * \brief Affiche le MenuButton
	 */
	void draw() override;

	/**
	 * \brief Mets � jour le MenuButton
	 */
	void update() override;

	/**
	 * \brief Nettoie le MenuButton
	 */
	void clean() override;

	/**
	 * \brief Associe une fonction callback au bouton
	 * \param callback La fonction callback que l'on souhaite associer
	 */
	void setCallback(void (*callback) ()) { _callback = callback;}

	/**
	 * \brief Retourne l'ID du callback associ� � ce bouton
	 * \return L'ID du callback associ�
	 */
	int getCallbackID() const {return _callbackID;}

private:
	/**
	 * \brief La fonction callback associ� au bouton
	 */
	void (*_callback) ();

	/**
	 * \brief Bool�en d�terminant si le bouton a �t� relach� ou non
	 */
	bool released;

	/**
	 * \brief L'ID du callback associ� au bouton
	 */
	int _callbackID;

	/**
	 * \brief Les �tats des boutons de souris possible
	 */
	enum button_state {
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
};

/**
 * \brief Le cr�ateur de MenuButton
 */
class MenuButtonCreator : public BaseCreator {
	/**
	 * \brief Cr�er un nouveau MenuButton
	 * \return Un nouveau MenuButton
	 */
	GameObject * createGameObject() const override {
		return new MenuButton();
	}
};