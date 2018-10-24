#pragma once
#include <vector>
#include "Player.h"

/**
 * \brief G�re les joueurs
 */
class PlayerManager {
public:

	/**
	 * \brief Retourne l'instance du PlayerManager
	 * \return L'instance du PlayerManager
	 */
	static PlayerManager * Instance() {
		if(instance == nullptr)
			instance = new PlayerManager();

		return instance;
	}

	/**
	 * \brief Initialise le PlayerManager
	 */
	void init() const;

	/**
	 * \brief Mets � jours les joueurs
	 */
	void update() const;

	/**
	 * \brief Affiche � l'�cran les joueurs
	 */
	void render() const;

	/**
	 * \brief Nettoie les joueurs
	 */
	void clear() const;

	/**
	 * \brief Retourne la liste des joueurs
	 * \return La liste des joueurs
	 */
	std::vector<Player *> * getPlayers() const { return players; }

	/**
	 * \brief Permet de d�terminer si tous les joueurs sont en vie ou non
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
	 * \brief La liste des joueurs pr�sents dans le niveau
	 */
	std::vector<Player *> * players = new std::vector<Player *>();
};

