#pragma once
#include "LoadParameters.h"
#include "Vector2D.h"
#include "Sprite.h"

/**
 * \brief La classe qui permet de gérer les éléments graphiques du jeu.
 */
class GameObject {
public:
	/**
	 * \brief Charge le GameObject en fonction du LoadParameters
	 * \param parameters Les paramètres du GameObject
	 */
	virtual void load(const LoadParameters* parameters);

	/**
	 * \brief Affiche le GameObject
	 */
	virtual void draw();

	/**
	 * \brief Mets à jour le GameObject
	 */
	virtual void update();

	/**
	 * \brief Nettoie le GameObject
	 */
	virtual void clean();

	/**
	 * \brief Retourne la position du GameObject (haut gauche du sprite)
	 */
	Vector2D& getPosition();

	/**
	 * \brief Positionne le GameObject
	 * \param newPosition La nouvelle position du GameObject
	 */
	void setPosition(Vector2D newPosition);

	/**
	 * \brief Positionne le GameObject
	 * \param new_x La nouvelle position en X
	 * \param new_y La nouvelle position en Y
	 */
	void setPosition(float new_x, float new_y);

	/**
	 * \brief Définie la vélocité du GameObject
	 * \param new_velocity La nouvelle vélocité
	 */
	void setVelocity(Vector2D new_velocity);

	/**
	 * \brief Définie la vélocité du GameObject
	 * \param new_x La nouvelle vélocité en X
	 * \param new_y La nouvelle vélocité en Y
	 */
	void setVelocity(float new_x, float new_y);

	/**
	 * \brief Définie l'angle du sprite (en degrès)
	 * \param new_angle Le nouvelle angle du sprite
	 */
	void setSpriteAngle(float new_angle) const;

	/**
	 * \brief Détermine si le GameObject est dedans ou en dehors des frontières de l'écran de jeu.
	 * \return Vrai si il est dehors, faux sinon.
	 */
	bool isOutsideScreenBondaries() const;

	/**
	 * \brief Retourne la largeur du sprite
	 * \return La largeur du sprite
	 */
	int getWidth() const;

	/**
	 * \brief Retourne la hauteur du sprite
	 * \return La hauteur du sprite
	 */
	int getHeight() const;


	Sprite* getSprite() const;

	/**
	 * \brief Permet de savoir si le GameObject est mort ou non
	 * \return Vrai s'il est mort, faux sinon
	 */
	bool isDead() const;

	/**
	 * \brief Retourne le SDL_Rect du sprite
	 */
	SDL_Rect getRect() const;

	GameObject() = default;

	virtual ~GameObject();

protected:

	/**
	 * \brief determine si le GameObject est mort ou non.
	 */
	bool is_dead{false};

	/**
	 * \brief La position du GameObject
	 */
	Vector2D position{};

	/**
	 * \brief La vitesse du GameObject
	 */
	Vector2D velocity{};

	/**
	 * \brief L'accélération du GameObject
	 */
	Vector2D acceleration{};

	/**
	 * \brief Le Sprite lié au GameObject
	 */
	Sprite * sprite{nullptr};

	/**
	 * \brief Booléen déterminant si le GameObject a déjà été nettoyé ou non.
	 */
	bool is_already_cleaned{false};
};

