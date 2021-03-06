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
	static BulletManager* Instance();

	/**
	 * \brief Initialise le BulletManager
	 */
	void init();

	/**
	 * \brief Cr�er un PlayerBullet avec la position et la velocit� donn�e en param�tre
	 * \param pLayer Le Player qui a tir� le Bullet
	 * \param pPosition La position du Bullet
	 * \param pVelocity La velocit� du Bullet
	 */
	void createPlayerBullet(PLAYER_NUM pLayer, const Vector2D pPosition, const Vector2D pVelocity);

	/**
	 * \brief Cr�er un EnemyBullet avec la position et la velocit� donn�e en param�tre
	 * \param pPosition La position du Bullet
	 * \param pVelocity La velocit� du Bullet
	 */
	void createEnemyBullet(Vector2D pPosition, Vector2D pVelocity);

	/**
	 * \brief Affiches les Bullets � l'�cran
	 */
	void render() const;

	/**
	 * \brief Mets � jour les Bullets
	 */
	void update();

	/**
	 * \brief Nettoie de la m�moire le BulletManager
	 */
	void clear();

	/**
	 * \brief Retourne la liste des Bullets des players
	 * \return La liste des Bullets des players
	 */
	PlayerBullet* getPlayerBullets() const;

	/**
	 * \brief Retourne la liste des Bullets ennemis
	 * \return La liste des Bullets ennemis
	 */
	EnemyBullet* getEnemyBullets() const;

	/**
	 * \brief La taille de la piscine de PlayerBullet
	 */
	static const int player_bullet_pool_size{50};

	/**
	 * \brief La taille de la piscine d'EnemyBullet
	 */
	static const int enemy_bullet_pool_size{500};

	~BulletManager();

private:
	BulletManager() = default;

	/**
	 * \brief L'instance du BulletManager
	 */
	static BulletManager * instance;

	/**
	 * \brief Setup un bullet
	 * \param bullet Le Bullet � param�trer
	 * \param position Sa position de d�part
	 * \param velocity Sa v�locit� de d�part
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
		PlayerBullet * firstPlayerBulletAvailable{nullptr};

		/**
		 * \brief Le premier EnemyBullet disponible
		 */
		EnemyBullet * firstEnemyBulletAvailable{nullptr};

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

