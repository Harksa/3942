#pragma once
#include "GameState.h"
#include "FontCache/SDL_FontCache.h"

/**
 * \brief Etat d'attente de reconnection de la manette
 */
class ReconnectJoystickState :
	public GameState {
public:
	ReconnectJoystickState() = default;
	~ReconnectJoystickState() = default;

	/**
	 * \brief Mets � jour l'�tat
	 */
	void update() override;

	/**
	 * \brief Affiche l'�tat � l'�cran
	 */
	void render() override;

	/**
	 * \brief Actions r�alis�es � l'entr� dans l'�tat
	 */
	bool onEnter() override;

	/**
	 * \brief Actions r�alis�s � la sortie de l'�tat
	 */
	bool onExit() override;

	/**
	 * \brief Retourne le StateID de cet �tat
	 * \return Le StateID de l'�tat
	 */
	std::string getStateID() const override {return RECONNECT_STATE_ID; }

private:
	/**
	 * \brief Le StateID de cet �tat
	 */
	static const std::string RECONNECT_STATE_ID;

	/**
	 * \brief La police utilis� pour afficher le message
	 */
	FC_Font * fc_font;
};

