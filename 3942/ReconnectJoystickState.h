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
	 * \brief Mets à jour l'état
	 */
	void update() override;

	/**
	 * \brief Affiche l'état à l'écran
	 */
	void render() override;

	/**
	 * \brief Actions réalisées à l'entré dans l'état
	 */
	bool onEnter() override;

	/**
	 * \brief Actions réalisés à la sortie de l'état
	 */
	bool onExit() override;

	/**
	 * \brief Retourne le StateID de cet état
	 * \return Le StateID de l'état
	 */
	std::string getStateID() const override {return RECONNECT_STATE_ID; }

private:
	/**
	 * \brief Le StateID de cet état
	 */
	static const std::string RECONNECT_STATE_ID;

	/**
	 * \brief La police utilisé pour afficher le message
	 */
	FC_Font * fc_font;
};

