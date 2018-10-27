#pragma once
#include "LoadParameters.h"
#include "Vector2D.h"
#include "Sprite.h"

/**
 * \brief La classe qui permet de g�rer les �l�ments graphiques du jeu.
 */
class GameObject {
public:
	/**
	 * \brief Charge le GameObject en fonction du LoadParameters
	 * \param parameters Les param�tres du GameObject
	 */
	virtual void load(const LoadParameters* parameters);

	/**
	 * \brief Affiche le GameObject
	 */
	virtual void draw();

	/**
	 * \brief Mets � jour le GameObject
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
	 * \brief D�finie la v�locit� du GameObject
	 * \param new_velocity La nouvelle v�locit�
	 */
	void setVelocity(Vector2D new_velocity);

	/**
	 * \brief D�finie la v�locit� du GameObject
	 * \param new_x La nouvelle v�locit� en X
	 * \param new_y La nouvelle v�locit� en Y
	 */
	void setVelocity(float new_x, float new_y);

	/**
	 * \brief D�finie l'angle du sprite (en degr�s)
	 * \param new_angle Le nouvelle angle du sprite
	 */
	void setSpriteAngle(float new_angle) const;

	/**
	 * \brief D�termine si le GameObject est dedans ou en dehors des fronti�res de l'�cran de jeu.
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
	 * \brief L'acc�l�ration du GameObject
	 */
	Vector2D acceleration{};

	/**
	 * \brief Le Sprite li� au GameObject
	 */
	Sprite * sprite{nullptr};

	/**
	 * \brief Bool�en d�terminant si le GameObject a d�j� �t� nettoy� ou non.
	 */
	bool is_already_cleaned{false};
};

