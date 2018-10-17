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
	 * \brief Charge le KeyboardOptionButton avec les param�tres rentr�s
	 * \param parameters Les param�tres du KeyboardOptionButton
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Dessine le KeyboardOptionButton � l'�cran
	 */
	void draw() override;

	/**
	 * \brief Mets � jour le KeyboardOptionButton
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
	 * \brief D�finie le joueur associ� au contr�le du KeyboardOptionButton
	 * \param player le joueur associ�
	 */
	void setAssociatedPlayer(PLAYER_NUM player) { associate_player = player; }

	/**
	 * \brief Renvoie le joueur associ� � ce boutton
	 * \return Le joueur associ� � ce boutton
	 */
	PLAYER_NUM getPlayerNum() const {return associate_player; }

	/**
	 * \brief D�finie les contr�les associ�s � ce KeyboardOptionButton
	 * \param control Le control associ�
	 */
	void setAssociatedControl(CONTROLS control) {associated_control = control; }

	/**
	 * \brief Retourne le contr�le associ� � ce boutton
	 */
	CONTROLS getAssociatedControl() const {return associated_control; }
private:

	/**
	 * \brief Le rect ou sera affich� le texte du bouton
	 */
	SDL_Rect text_rect;

	/**
	 * \brief Le joueur associ� � ce boutton
	 */
	PLAYER_NUM associate_player{PLAYER_1};

	/**
	 * \brief Le contr�le associ� � ce boutton
	 */
	CONTROLS associated_control{MOVE_UP_KEY};
};

