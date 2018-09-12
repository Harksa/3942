#pragma once
#include "Bullet.h"

/**
 * \brief Classe représentant les Bullets tirés par les ennemis
 */
class EnemyBullet :
	public Bullet {
public:
	EnemyBullet() = default;
	~EnemyBullet() = default;

	/**
	 * \brief Affiche le Bullet à l'écran
	 */
	void draw() override;

	/**
	 * \brief Mets à jour le Bullet
	 */
	void update() override;

	/**
	 * \brief Nettoie le Bullet de la mémoire
	 */
	void clean() override;

	/**
	 * \brief Actions effecttuées lorsque le Bullet rentre en collision avec un autre objet.
	 */
	void onCollision() override;

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param parameters Les paramètres du Bullet
	 */
	void load(const LoadParameters* parameters) override;


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

