#pragma once
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief La classe qui d�signe l'avatar du joueur
 */
class Player : public SDLGameObject {
public:
	Player();

	/**
	 * \brief Charge le Player en fonction du LoadParameters
	 * \param parameters Les attributs du Player
	 */
	void load(const LoadParameters* parameters) override;

	/**
	 * \brief Affiche le Player
	 */
	void draw() override;

	/**
	 * \brief Mets � jour le Player
	 */
	void update() override;

	/**
	 * \brief Nettoie le Player
	 */
	void clean() override;

private:
	/**
	 * \brief Prend en charge les input du joueur
	 */
	void handleInput();

	/**
	 * \brief G�re la cr�ation de Bullet par le Player.
	 */
	void handleBulletSpawner();

	/**
	 * \brief Vitesse de d�placement du joueur
	 */
	const float speed = 5.0f;

	/**
	 * \brief La largeur par 2 du sprite du Bullet tir� par le Player.
	 * Utilis� pour le cr�er correctement au milieu.
	 */
	int bullet_sprite_width_by2;
};

/**
 * \brief La classe permettant de cr�er un player
 */
class PlayerCreator : public BaseCreator {
	/**
	 * \brief Cr�er un Player
	 * \return Un nouveau Player
	 */
	GameObject * createGameObject() const override {
		return new Player();
	}
};

