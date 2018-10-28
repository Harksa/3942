#pragma once
#include "Bullet.h"
#include "PlayerEnum.h"

/**
 * \brief Classe repr�sentant les Bullets tir�s par le joueur
 */
class PlayerBullet :
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
	 * \brief D�finie le Player qui a tir� le Bullet
	 * \param pPlayer Le player qui a tir� le Bullet
	 */
	void setPlayerNum(PLAYER_NUM pPlayer);

	/**
	 * \brief Retourne l'ID du Player ayant tir� ce Bullet
	 * \return L'ID du Player ayant tir� ce Bullet
	 */
	PLAYER_NUM getPlayerNum() const;

	/**
	 * \brief Mets � jour le voisin de ce Bullet
	 * \param pNewBullet Le nouveau voisin
	 */
	void setNext(PlayerBullet* pNewBullet);

	/**
	 * \brief Retourne le voisin de ce Bullet
	 * \return Le voisin de ce Bullet
	 */
	PlayerBullet* getNext() const;

	PlayerBullet() = default;
	~PlayerBullet() = default;

private:
	/**
	 * \brief Le voisin de ce Bullet
	 */
	PlayerBullet * next{};

	/**
	 * \brief Le Player ayant tir� la balle
	 */
	PLAYER_NUM player_num{};
};

