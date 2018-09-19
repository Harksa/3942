#pragma once
#include "Bullet.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"

/**
 * \brief Cette classe g�re les piscines de Bullet et permet d'en cr�er
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
	 * \brief Cr�er un PlayerBullet avec la position et la velocit� donn�e en param�tre
	 * \param position La position du Bullet
	 * \param velocity La velocit� du Bullet
	 */
	void createPlayerBullet(Vector2D position, Vector2D velocity);

	/**
	 * \brief Cr�er un EnemyBullet avec la position et la velocit� donn�e en param�tre
	 * \param position La position du Bullet
	 * \param velocity La velocit� du Bullet
	 */
	void createEnemyBullet(Vector2D position, Vector2D velocity);

	/**
	 * \brief Affiches les Bullets � l'�cran
	 */
	void render();

	/**
	 * \brief Mets � jour les Bullets
	 */
	void update();

	/**
	 * \brief Nettoie de la m�moire le BulletManager
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

