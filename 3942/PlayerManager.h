#pragma once
#include <vector>
#include "Player.h"

/**
 * \brief Gère les joueurs
 */
class PlayerManager {
public:

	/**
	 * \brief Retourne l'instance du PlayerManager
	 * \return L'instance du PlayerManager
	 */
	static PlayerManager* Instance();

	/**
	 * \brief Initialise le PlayerManager
	 */
	void init();

	/**
	 * \brief Mets à jours les joueurs
	 */
	void update();

	/**
	 * \brief Affiche à l'écran les joueurs
	 */
	void render() const;

	/**
	 * \brief Nettoie les joueurs
	 */
	void clear();

	/**
	 * \brief Retourne la liste des joueurs
	 * \return La liste des joueurs
	 */
	std::vector<Player *> getPlayers() const;

	/**
	 * \brief Permet de déterminer si tous les joueurs sont en vie ou non
	 * \return Faux si au moins un joueur est en vie, faux sinon.
	 */
	bool doesAllPlayersDoesntHaveAnyRemainingLives() const;

private:

	PlayerManager() = default;

	/**
	 * \brief L'instance de PlayerManager
	 */
	static PlayerManager * instance;

	/**
	 * \brief La liste des joueurs présents dans le niveau
	 */
	std::vector<Player *> players;
};

