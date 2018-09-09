#pragma once
#include "Bullet.h"
#include "PlayerBullet.h"

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
	 * \brief Créer un Bullet avec la position et la velocité donnée en paramètre
	 * \param position La position du Bullet
	 * \param velocity La velocité du Bullet
	 */
	void createPlayerBullet(Vector2D position, Vector2D velocity);

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

private:
	BulletManager();
	~BulletManager();

	/**
	 * \brief Le premier Bullet available
	 */
	PlayerBullet * firstPlayerBulletAvailable;

	/**
	 * \brief L'instance du BulletManager
	 */
	static BulletManager * instance;

	/**
	 * \brief La taille de la piscine de Bullet
	 */
	static const int player_bullet_pool_size = 100;

	/**
	 * \brief Le tableau de Bullet
	 */
	PlayerBullet player_bullets[player_bullet_pool_size]; 
};

