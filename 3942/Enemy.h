#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "PlayerEnum.h"

/**
 * \brief La classe ennemi de base
 */
class Enemy : public GameObject {
public:

	Enemy();

	/**
	 * \brief Dessine l'ennemi
	 */
	void draw() override;

	/**
	 * \brief Mets à jour l'ennemi
	 */
	void update() override;

	/**
	 * \brief Nettoie l'ennemi de la mémoire
	 */
	void clean() override;

	/**
	 * \brief Charge l'ennemi avec les paramètres donnés
	 * \param parameters Les paramètres de cet Enemy
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Action réalisé lorsque l'Enemy est rentré en collision avec un Bullet
	 * \param player_bullet_num Le Player ayant tiré la balle.
	 */
	void onCollisionWithBullet(PLAYER_NUM player_bullet_num);

	/**
	 * \brief Action réalisé lorsque l'Enemy rentre en collision avec un Player
	 */
	void onCollisionWithPlayer();

	/**
	 * \brief Assigne les points gagnés en tuer cet ennemi
	 * \param p Les points de cet ennemi
	 */
	void setPoints(unsigned int p) { points = p; }

	/**
	 * \brief Assigne la vie de cet ennemi
	 * \param h La vie de cet ennemi
	 */
	void setHealth(int h) { health = h; }

private:
	/**
	 * \brief La vie de l'enemi.
	 */
	int health;

	/**
	 * \brief Points donnés par l'ennemi lorsqu'il a été tué par le joueur
	 */
	unsigned int points = 100;

	bool bulletCreated;
};

class EnemyCreator : public BaseCreator {
	GameObject* createGameObject() const override {
		return new Enemy();
	}
};