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
	 * \brief Initialise le BulletManager
	 */
	void init();

	/**
	 * \brief Créer un PlayerBullet avec la position et la velocité donnée en paramètre
	 * \param player Le Player qui a tiré le Bullet
	 * \param position La position du Bullet
	 * \param velocity La velocité du Bullet
	 */
	void createPlayerBullet(PLAYER_NUM player, const Vector2D position, const Vector2D velocity);

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

	/**
	 * \brief Retourne la liste des Bullets des players
	 * \return La liste des Bullets des players
	 */
	PlayerBullet * getPlayerBullets() const { return bullet_pool->player_bullets;}

	/**
	 * \brief Retourne la liste des Bullets ennemis
	 * \return La liste des Bullets ennemis
	 */
	EnemyBullet * getEnemyBullets() const { return bullet_pool->enemy_bullets;}

	/**
	 * \brief La taille de la piscine de PlayerBullet
	 */
	static const int player_bullet_pool_size = 50;

	/**
	 * \brief La taille de la piscine d'EnemyBullet
	 */
	static const int enemy_bullet_pool_size = 500;

	~BulletManager();

private:
	BulletManager() = default;

	/**
	 * \brief L'instance du BulletManager
	 */
	static BulletManager * instance;

	/**
	 * \brief Setup un bullet
	 * \param bullet Le Bullet à paramétrer
	 * \param position Sa position de départ
	 * \param velocity Sa vélocité de départ
	 */
	void setupBullet(Bullet* bullet, Vector2D position, Vector2D velocity) const;

	bool is_already_cleared {false};

	/**
	 * \brief La structure regroupant les piscines de Bullets
	 */
	struct BulletPool {

		/**
		 * \brief Le premier PlayerBullet disponible
		 */
		PlayerBullet * firstPlayerBulletAvailable{};

		/**
		 * \brief Le premier EnemyBullet disponible
		 */
		EnemyBullet * firstEnemyBulletAvailable{};

		/**
		 * \brief Le tableau de PlayerBullet
		 */
		PlayerBullet player_bullets[player_bullet_pool_size];

		/**
		 * \brief Le tableau d'EnemyBullet
		 */
		EnemyBullet enemy_bullets[enemy_bullet_pool_size];

		BulletPool() = default;
		~BulletPool() = default;
	};

	/**
	 * \brief La piscine de Bullet
	 */
	BulletPool * bullet_pool{};

};

