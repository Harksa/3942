#pragma once
#include "GameObject.h"
#include "LoadParameters.h"
#include "Vector2D.h"
#include "Sprite.h"

/**
 * \brief La classe qui permet de g�rer les �l�ments graphiques du jeu.
 */
class SDLGameObject : public GameObject {
public:
	SDLGameObject();

	/**
	 * \brief Charge le SDLGameObject en fonction du LoadParameters
	 * \param parameters Les param�tres du SDLGameObject
	 */
	void load(const LoadParameters *parameters) override {
		position = Vector2D(parameters->getX(), parameters->getY());
		velocity =  acceleration = Vector2D(0,0);

		sprite = new Sprite(parameters->getWidth(), parameters->getHeight(),parameters->getNumFrames(), parameters->getTextureID());
	}

	/**
	 * \brief Affiche le SDLGameObject
	 */
	void draw() override;

	/**
	 * \brief Mets � jour le SDLGameObject
	 */
	void update() override;

	/**
	 * \brief Nettoie le SDLGameObject
	 */
	void clean() override;

	/**
	 * \brief Retourne la position du SDLGameObject (haut gauche du sprite)
	 */
	Vector2D & getPosition() {return position;}

	/**
	 * \brief Retourne la largeur du sprite
	 * \return La largeur du sprite
	 */
	int getWidth() const {return sprite->getWidth();}

	/**
	 * \brief Retourne la hauteur du sprite
	 * \return La hauteur du sprite
	 */
	int getHeight() const {return sprite->getHeight();}

protected:
	/**
	 * \brief La position du SDLGameObject
	 */
	Vector2D position;

	/**
	 * \brief La vitesse du SDLGameObject
	 */
	Vector2D velocity;

	/**
	 * \brief L'acc�l�ration du SDLGameObject
	 */
	Vector2D acceleration;

	/**
	 * \brief Le Sprite li� au SDLGameObject
	 */
	Sprite * sprite;
};

