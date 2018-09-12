#pragma once
#include "Bullet.h"

class EnemyBullet :
	public Bullet {
public:
	EnemyBullet() = default;
	~EnemyBullet() = default;

	void draw() override;
	void update() override;
	void clean() override;
	void load(const LoadParameters* parameters) override;
	void onCollision() override;

	/**
	 * \brief Mets à jour le voisin de ce Bullet
	 * \param new_bullet Le nouveau voisin
	 */
	void setNext(EnemyBullet * new_bullet) {next = new_bullet;}

	/**
	 * \brief Retourne le voisin de ce Bullet
	 * \return Le voisin de ce Bullet
	 */
	EnemyBullet * getNext() const {return next;}

private:
	/**
	 * \brief Le voisin de ce Bullet
	 */
	EnemyBullet * next{};
};

