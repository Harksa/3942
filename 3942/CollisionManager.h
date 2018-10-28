#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"

/**
 * \brief Cette classe g�re les collisions entre les diff�rents GameObjects
 */
class CollisionManager {
public:

	/**
	 * \brief G�re les collisions entre les PlayerBullets et les autres GameObjects
	 * \param pObjects Les GameObjects de la sc�ne
	 */
	static void checkCollisionEnemyWithPlayerBullets(std::vector<GameObject*> &pObjects);

	/**
	 * \brief G�re les collisions des EnemyBullets avec le Player
	 * \param pPlayer Le player dont on va v�rifier les collisions.
	 */
	static void checkCollisionPlayerWithEnemyBullets(Player * pPlayer);
	
	/**
	 * \brief G�re la collision entre joueurs et ennemis
	 * \param pPlayer Le joueur
	 * \param pObjects La liste des objets du jeu
	 */
	static void checkCollisionsPlayerAgainstEnemies(Player* pPlayer, std::vector<GameObject*>& pObjects);

};

