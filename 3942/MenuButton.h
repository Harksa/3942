#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief Boutton de menu. Le joueur peut cliquer dessus et une action sera effectué en fonction du callback associé.
 */
class MenuButton : public GameObject {
public:
	/**
	 * \brief Charge le MenuButton avec les paramètres du LoadParameter
	 * \param pParameters Le LoadParameters contenant les informations du MenuButton
	 */
	void load(const LoadParameters *pParameters) override;

	/**
	 * \brief Affiche le MenuButton
	 */
	void draw() override;

	/**
	 * \brief Mets à jour le MenuButton
	 */
	void update() override;

	/**
	 * \brief Nettoie le MenuButton
	 */
	void clean() override;

	/**
	 * \brief Associe une fonction callback au bouton
	 * \param pCallback La fonction callback que l'on souhaite associer
	 */
	void setCallback(void (*pCallback)());

	/**
	 * \brief Retourne l'ID du callback associé à ce bouton
	 * \return L'ID du callback associé
	 */
	int getCallbackId() const;

	 MenuButton() = default;

protected:
	
	/**
	 * \brief Les états des boutons de souris possible
	 */
	enum button_state {
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	/**
	 * \brief Booléen déterminant si le bouton a été relaché ou non
	 */
	bool released {true};

private:
	/**
	 * \brief La fonction callback associé au bouton
	 */
	void (*callback)() {nullptr};

	/**
	 * \brief L'ID du callback associé au bouton
	 */
	int callback_id{0};

};

/**
 * \brief Le créateur de MenuButton
 */
class MenuButtonCreator : public BaseCreator {
	/**
	 * \brief Créer un nouveau MenuButton
	 * \return Un nouveau MenuButton
	 */
	GameObject * createGameObject() const override {
		return new MenuButton();
	}
};