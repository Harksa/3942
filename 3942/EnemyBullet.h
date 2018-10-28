#pragma once
#include "Bullet.h"

/**
 * \brief Classe repr�sentant les Bullets tir�s par les ennemis
 */
class EnemyBullet :
	public Bullet {
public:
	/**
	 * \brief Affiche le Bullet � l'�cran
	 */
	void draw() override;

	/**
	 * \brief Mets � jour le Bullet
	 */
	void update() override;

	/**
	 * \brief Nettoie le Bullet de la m�moire
	 */
	void clean() override;

	/**
	 * \brief Actions effecttu�es lorsque le Bullet rentre en collision avec un autre objet.
	 */
	void onCollision() override;

	/**
	 * \brief Charge le Bullet en fonction du LoadParameter
	 * \param pParameters Les param�tres du Bullet
	 */
	void load(const LoadParameters* pParameters) override;

	/**
	 * \brief Mets � jour le voisin de ce Bullet
	 * \param pNewBullet Le nouveau voisin
	 */
	void setNext(EnemyBullet* pNewBullet);

	/**
	 * \brief Retourne le voisin de ce Bullet
	 * \return Le voisin de ce Bullet
	 */
	EnemyBullet* getNext() const;

	EnemyBullet() = default;
	~EnemyBullet() = default;

private:
	/**
	 * \brief Le voisin de ce Bullet
	 */
	EnemyBullet * next{};
};
