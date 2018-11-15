#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "PlayerEnum.h"

/**
 * \brief La classe qui désigne l'avatar du joueur
 */
class Player : public GameObject {
public:
	/**
	 * \brief Créer un player
	 * \param pNum L'ID du player
	 */
	Player(PLAYER_NUM pNum = PLAYER_1);

	/**
	 * \brief Charge le Player en fonction du LoadParameters
	 * \param pParameters Les attributs du Player
	 */
	void load(const LoadParameters* pParameters) override;

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
	 * \brief Détermine l'ID du joystick associé à ce joueur
	 * \param pJoyId l'ID du joystick
	 */
	void setJoystickID(unsigned int pJoyId);

	/**
	 * \brief Retourne le joystickID du joueur
	 * \return Le joystickID du joueur
	 */
	unsigned int getJoystickID() const;

	/**
	 * \brief Permet de déterminer si le contrôlleur du joueur est connecté ou non
	 * \return Vrai si le joystick est connecté, faux sinon.
	 */
	bool isJoyConnected() const;

	/**
	 * \brief Actions effectués lorsque le joueur rentre en collision avec un autre objet
	 */
	void onCollision();

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
	const float speed{5.0f};

	/**
	 * \brief Le délai entre deux tires
	 */
	const int fire_delay{10};

	/**
	 * \brief Le timer qui permettra de savoir si le joueur peut tirer ou non.
	 */
	int timer_fire{0};

	/**
	 * \brief La largeur par 2 du sprite du Bullet tiré par le Player.
	 * Utilisé pour le créer correctement au milieu.
	 */
	int bullet_sprite_width_by2{};

	/**
	 * \brief Les vies du joueur
	 */
	int lives{3};

	/**
	 * \brief L'ID du joueur
	 */
	PLAYER_NUM id{};

	/**
	 * \brief L'ID du joystick utilisé par le joueur
	 */
	unsigned int joystick_id{}; 
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

