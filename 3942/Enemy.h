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
	 * \param parameters Les param�tres de cet Enemy
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Action r�alis� lorsque l'Enemy est rentr� en collision avec un Bullet
	 * \param player_bullet_num Le Player ayant tir� la balle.
	 */
	void onCollisionWithBullet(PLAYER_NUM player_bullet_num);

	/**
	 * \brief Action r�alis� lorsque l'Enemy rentre en collision avec un Player
	 */
	void onCollisionWithPlayer();

	/**
	 * \brief Assigne les points gagn�s en tuer cet ennemi
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
	 * \brief Points donn�s par l'ennemi lorsqu'il a �t� tu� par le joueur
	 */
	unsigned int points = 100;

	bool bulletCreated;
};

class EnemyCreator : public BaseCreator {
	GameObject* createGameObject() const override {
		return new Enemy();
	}
};