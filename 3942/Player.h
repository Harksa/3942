#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "PlayerEnum.h"

/**
 * \brief La classe qui d�signe l'avatar du joueur
 */
class Player : public GameObject {
public:
	/**
	 * \brief Cr�er un player
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
	 * \brief Mets � jour le Player
	 */
	void update() override;

	/**
	 * \brief Nettoie le Player
	 */
	void clean() override;

	/**
	 * \brief D�termine l'ID du joystick associ� � ce joueur
	 * \param pJoyId l'ID du joystick
	 */
	void setJoystickID(unsigned int pJoyId);

	/**
	 * \brief Retourne le joystickID du joueur
	 * \return Le joystickID du joueur
	 */
	unsigned int getJoystickID() const;

	/**
	 * \brief Permet de d�terminer si le contr�lleur du joueur est connect� ou non
	 * \return Vrai si le joystick est connect�, faux sinon.
	 */
	bool isJoyConnected() const;

	/**
	 * \brief Actions effectu�s lorsque le joueur rentre en collision avec un autre objet
	 */
	void onCollision();

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
	const float speed{5.0f};

	/**
	 * \brief Le d�lai entre deux tires
	 */
	const int fire_delay{10};

	/**
	 * \brief Le timer qui permettra de savoir si le joueur peut tirer ou non.
	 */
	int timer_fire{0};

	/**
	 * \brief La largeur par 2 du sprite du Bullet tir� par le Player.
	 * Utilis� pour le cr�er correctement au milieu.
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
	 * \brief L'ID du joystick utilis� par le joueur
	 */
	unsigned int joystick_id{}; 
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

