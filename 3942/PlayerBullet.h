#pragma once
#include "Bullet.h"
#include "PlayerEnum.h"

/**
 * \brief Classe représentant les Bullets tirés par le joueur
 */
class PlayerBullet :
	public Bullet {
public:

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
	 * \param pParameters Les paramètres du Bullet
	 */
	void load(const LoadParameters* pParameters) override;

	/**
	 * \brief Définie le Player qui a tiré le Bullet
	 * \param pPlayer Le player qui a tiré le Bullet
	 */
	void setPlayerNum(PLAYER_NUM pPlayer);

	/**
	 * \brief Retourne l'ID du Player ayant tiré ce Bullet
	 * \return L'ID du Player ayant tiré ce Bullet
	 */
	PLAYER_NUM getPlayerNum() const;

	/**
	 * \brief Mets à jour le voisin de ce Bullet
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
	 * \brief Le Player ayant tiré la balle
	 */
	PLAYER_NUM player_num{};
};

