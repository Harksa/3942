#pragma once
#include "MenuButton.h"
#include "KeyboardControls.h"

/**
 * \brief Boutton permettant de changer les valeurs du clavier
 */
class KeyboardOptionButton : public MenuButton {
public:
	/**
	 * \brief Charge le KeyboardOptionButton avec les paramètres rentrés
	 * \param pParameters Les paramètres du KeyboardOptionButton
	 */
	void load(const LoadParameters* pParameters) override;

	/**
	 * \brief Dessine le KeyboardOptionButton à l'écran
	 */
	void draw() override;

	/**
	 * \brief Mets à jour le KeyboardOptionButton
	 */
	void update() override;

	/**
	 * \brief Nettoie le KeyboardOptionButton
	 */
	void clean() override;

	/**
	 * \brief Définie le joueur associé au contrôle du KeyboardOptionButton
	 * \param pPlayer le joueur associé
	 */
	void setAssociatedPlayer(PLAYER_NUM pPlayer);

	/**
	 * \brief Renvoie le joueur associé à ce boutton
	 * \return Le joueur associé à ce boutton
	 */
	PLAYER_NUM getPlayerNum() const;

	/**
	 * \brief Définie le contrôle associé à ce KeyboardOptionButton
	 * \param pControl Le contrôle associé
	 */
	void setAssociatedControl(CONTROLS pControl);

	/**
	 * \brief Retourne le contrôle associé à ce boutton
	 */
	CONTROLS getAssociatedControl() const;

	KeyboardOptionButton() = default;
	~KeyboardOptionButton() = default;

private:

	/**
	 * \brief La fonction callback appelée par ce bouton
	 */
	void callbackFunction() const;

	/**
	 * \brief Le rect ou sera affiché le texte du bouton
	 */
	SDL_Rect text_rect;

	/**
	 * \brief Le joueur associé à ce boutton
	 */
	PLAYER_NUM associate_player{PLAYER_1};

	/**
	 * \brief Le contrôle associé à ce boutton
	 */
	CONTROLS associated_control{MOVE_UP_KEY};
};

