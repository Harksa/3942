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
	 * \param pParameters Les paramètres de cet Enemy
	 */
	void load(const LoadParameters* pParameters) override;

	/**
	 * \brief Action réalisé lorsque l'Enemy est rentré en collision avec un Bullet
	 * \param pLayerBulletNum Le Player ayant tiré la balle.
	 */
	void onCollisionWithBullet(PLAYER_NUM pLayerBulletNum);

	/**
	 * \brief Action réalisé lorsque l'Enemy rentre en collision avec un Player
	 */
	void onCollisionWithPlayer();

	/**
	 * \brief Assigne les points gagnés en tuer cet ennemi
	 * \param pPoints Les points de cet ennemi
	 */
	void setPoints(unsigned int pPoints);

	/**
	 * \brief Assigne la vie de cet ennemi
	 * \param pHealth La vie de cet ennemi
	 */
	void setHealth(int pHealth);

private:
	/**
	 * \brief La vie de l'enemi.
	 */
	int health;

	/**
	 * \brief Points donnés par l'ennemi lorsqu'il a été tué par le joueur
	 */
	unsigned int points;

	bool bullet_created;
};

class EnemyCreator : public BaseCreator {
	GameObject* createGameObject() const override {
		return new Enemy();
	}
};