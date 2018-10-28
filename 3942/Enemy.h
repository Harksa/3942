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
	 * \brief Mets � jour l'ennemi
	 */
	void update() override;

	/**
	 * \brief Nettoie l'ennemi de la m�moire
	 */
	void clean() override;

	/**
	 * \brief Charge l'ennemi avec les param�tres donn�s
	 * \param pParameters Les param�tres de cet Enemy
	 */
	void load(const LoadParameters* pParameters) override;

	/**
	 * \brief Action r�alis� lorsque l'Enemy est rentr� en collision avec un Bullet
	 * \param pLayerBulletNum Le Player ayant tir� la balle.
	 */
	void onCollisionWithBullet(PLAYER_NUM pLayerBulletNum);

	/**
	 * \brief Action r�alis� lorsque l'Enemy rentre en collision avec un Player
	 */
	void onCollisionWithPlayer();

	/**
	 * \brief Assigne les points gagn�s en tuer cet ennemi
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
	 * \brief Points donn�s par l'ennemi lorsqu'il a �t� tu� par le joueur
	 */
	unsigned int points;

	bool bullet_created;
};

class EnemyCreator : public BaseCreator {
	GameObject* createGameObject() const override {
		return new Enemy();
	}
};