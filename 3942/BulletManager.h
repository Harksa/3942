#pragma once
#include "Bullet.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"

/**
 * \brief Cette classe gère les piscines de Bullet et permet d'en créer
 */
class BulletManager {
public:
	/**
	 * \brief Retourne l'instance de BulletManager
	 * \return L'instance de BulletManager
	 */
	static BulletManager * Instance() {
		if(instance == nullptr) {
			instance = new BulletManager();
		}

		return instance;
	}

	/**
	 * \brief Créer un PlayerBullet avec la position et la velocité donnée en paramètre
	 * \param position La position du Bullet
	 * \param velocity La velocité du Bullet
	 */
	void createPlayerBullet(Vector2D position, Vector2D velocity);

	/**
	 * \brief Créer un EnemyBullet avec la position et la velocité donnée en paramètre
	 * \param position La position du Bullet
	 * \param velocity La velocité du Bullet
	 */
	void createEnemyBullet(Vector2D position, Vector2D velocity);

	/**
	 * \brief Affiches les Bullets à l'écran
	 */
	void render();

	/**
	 * \brief Mets à jour les Bullets
	 */
	void update();

	/**
	 * \brief Nettoie de la mémoire le BulletManager
	 */
	void clear();

	PlayerBullet * getPlayerBullets() { return player_bullets;}

	EnemyBullet * getEnemyBullets() { return enemy_bullets;}

	/**
	 * \brief La taille de la piscine de PlayerBullet
	 */
	static const int player_bullet_pool_size = 50;

	/**
	 * \brief La taille de la piscine d'EnemyBullet
	 */
	static const int enemy_bullet_pool_size = 100;

private:
	BulletManager();
	~BulletManager();

	/**
	 * \brief Le premier PlayerBullet disponible
	 */
	PlayerBullet * firstPlayerBulletAvailable;

	/**
	 * \brief Le premier EnemyBullet disponible
	 */
	EnemyBullet * firstEnemyBulletAvailable;

	/**
	 * \brief L'instance du BulletManager
	 */
	static BulletManager * instance;

	/**
	 * \brief Le tableau de PlayerBullet
	 */
	PlayerBullet player_bullets[player_bullet_pool_size];

	/**
	 * \brief Le tableau d'EnemyBullet
	 */
	EnemyBullet enemy_bullets[enemy_bullet_pool_size];

	bool is_already_cleared = false;
};

