#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

/**
 * \brief La classe qui désigne l'avatar du joueur
 */
class Player : public GameObject {
public:

	Player(int player_id = 0) : id{player_id} {}

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
	 * \brief Mets à jour le Player
	 */
	void update() override;

	/**
	 * \brief Nettoie le Player
	 */
	void clean() override;

	/**
	 * \brief Actions effectués lorsque le joueur rentre en collision avec un autre objet
	 */
	void onCollision() override;

	/**
	 * \brief Définie l'ID du player
	 * \param i L'ID du player
	 */
	void setID(int i) { id = i; }

private:
	/**
	 * \brief Prend en charge les input du joueur
	 */
	void handleInput();

	/**
	 * \brief Gère la création de Bullet par le Player.
	 */
	void handleBulletSpawner();

	/**
	 * \brief Vitesse de déplacement du joueur
	 */
	const float speed = 5.0f;

	/**
	 * \brief Le délai entre deux tires
	 */
	const int fireDelay = 10;

	/**
	 * \brief Le timer qui permettra de savoir si le joueur peut tirer ou non.
	 */
	int timerFire = 0;

	/**
	 * \brief La largeur par 2 du sprite du Bullet tiré par le Player.
	 * Utilisé pour le créer correctement au milieu.
	 */
	int bullet_sprite_width_by2{};

	/**
	 * \brief Les vies du joueur
	 */
	int lives = 3;

	/**
	 * \brief l'ID du player
	 */
	int id{};
};

/**
 * \brief La classe permettant de créer un player
 */
class PlayerCreator : public BaseCreator {
	/**
	 * \brief Créer un Player
	 * \return Un nouveau Player
	 */
	GameObject * createGameObject() const override {
		return new Player();
	}
};

