#pragma once
#include "MenuButton.h"
#include "KeyboardControls.h"

/**
 * \brief Boutton permettant de changer les valeurs du clavier
 */
class KeyboardOptionButton : public MenuButton {
public:
	/**
	 * \brief Charge le KeyboardOptionButton avec les param�tres rentr�s
	 * \param pParameters Les param�tres du KeyboardOptionButton
	 */
	void load(const LoadParameters* pParameters) override;

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

	/**
	 * \brief D�finie le joueur associ� au contr�le du KeyboardOptionButton
	 * \param pPlayer le joueur associ�
	 */
	void setAssociatedPlayer(PLAYER_NUM pPlayer);

	/**
	 * \brief Renvoie le joueur associ� � ce boutton
	 * \return Le joueur associ� � ce boutton
	 */
	PLAYER_NUM getPlayerNum() const;

	/**
	 * \brief D�finie le contr�le associ� � ce KeyboardOptionButton
	 * \param pControl Le contr�le associ�
	 */
	void setAssociatedControl(CONTROLS pControl);

	/**
	 * \brief Retourne le contr�le associ� � ce boutton
	 */
	CONTROLS getAssociatedControl() const;

	KeyboardOptionButton() = default;
	~KeyboardOptionButton() = default;

private:

	/**
	 * \brief La fonction callback appel�e par ce bouton
	 */
	void callbackFunction() const;

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

