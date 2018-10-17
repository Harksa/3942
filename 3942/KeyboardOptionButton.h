#pragma once
#include "MenuButton.h"
#include "KeyboardControls.h"

/**
 * \brief Boutton permettant de changer les valeurs du clavier
 */
class KeyboardOptionButton : public MenuButton {
public:
	KeyboardOptionButton() = default;
	~KeyboardOptionButton() = default;

	/**
	 * \brief Charge le KeyboardOptionButton avec les paramètres rentrés
	 * \param parameters Les paramètres du KeyboardOptionButton
	 */
	void load(const LoadParameters* parameters) override;

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


	Vector2D getTextPosition() const {
		Vector2D pos;
		pos.x = position.x + sprite->getWidth() * 0.3f;
		pos.y = position.y + sprite->getHeight() * 0.3f;
		return pos;
	}

	/**
	 * \brief Définie le joueur associé au contrôle du KeyboardOptionButton
	 * \param player le joueur associé
	 */
	void setAssociatedPlayer(PLAYER_NUM player) { associate_player = player; }

	/**
	 * \brief Renvoie le joueur associé à ce boutton
	 * \return Le joueur associé à ce boutton
	 */
	PLAYER_NUM getPlayerNum() const {return associate_player; }

	/**
	 * \brief Définie les contrôles associés à ce KeyboardOptionButton
	 * \param control Le control associé
	 */
	void setAssociatedControl(CONTROLS control) {associated_control = control; }

	/**
	 * \brief Retourne le contrôle associé à ce boutton
	 */
	CONTROLS getAssociatedControl() const {return associated_control; }
private:

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

