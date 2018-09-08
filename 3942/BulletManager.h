#pragma once
#include "Bullet.h"

/**
 * \brief Cette classe g�re les piscines de Bullet et permet d'en cr�er
 */
class BulletManager {
public:
	/**
	 * \brief Retourne l'instance de BulletManager
	 * \return L'instance de BulletManager
	 */
	static BulletManager * Instance() {
		if(instance == nullptr) {
			instance = new BulletManager();
		}

		return instance;
	}

	/**
	 * \brief Le premier Bullet available
	 */
	Bullet * firstAvailable;

	/**
	 * \brief Cr�er un Bullet avec la position et la velocit� donn�e en param�tre
	 * \param position La position du Bullet
	 * \param velocity La velocit� du Bullet
	 */
	void create(Vector2D position, Vector2D velocity);

	/**
	 * \brief Affiches les Bullets � l'�cran
	 */
	void render();

	/**
	 * \brief Mets � jour les Bullets
	 */
	void update();

	/**
	 * \brief Nettoie de la m�moire le BulletManager
	 */
	void clear();

private:
	BulletManager();
	~BulletManager();

	/**
	 * \brief L'instance du BulletManager
	 */
	static BulletManager * instance;

	/**
	 * \brief La taille de la piscine de Bullet
	 */
	static const int pool_size = 100;

	/**
	 * \brief Le tableau de Bullet
	 */
	Bullet bullets[pool_size]; 
};

