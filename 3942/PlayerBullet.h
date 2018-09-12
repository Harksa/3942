#pragma once
#include "Bullet.h"

/**
 * \brief Classe repr�sentant les Bullets tir�s par le joueur
 */
class PlayerBullet :
	public Bullet {
public:
	PlayerBullet() = default;
	~PlayerBullet() = default;

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
	 * \param parameters Les param�tres du Bullet
	 */
	void load(const LoadParameters* parameters) override;


	/**
	 * \brief Mets � jour le voisin de ce Bullet
	 * \param new_bullet Le nouveau voisin
	 */
	void setNext(PlayerBullet * new_bullet) {next = new_bullet;}

	/**
	 * \brief Retourne le voisin de ce Bullet
	 * \return Le voisin de ce Bullet
	 */
	PlayerBullet * getNext() const {return next;}

private:
	/**
	 * \brief Le voisin de ce Bullet
	 */
	PlayerBullet * next{};
};

