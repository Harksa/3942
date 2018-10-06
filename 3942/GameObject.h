#pragma once
#include "LoadParameters.h"
#include "Vector2D.h"
#include "Sprite.h"

/**
 * \brief La classe qui permet de g�rer les �l�ments graphiques du jeu.
 */
class GameObject {
public:
	GameObject() = default;

	virtual ~GameObject() {
		if(!is_already_cleaned) {
			delete sprite;
		}
	}

	/**
	 * \brief Charge le GameObject en fonction du LoadParameters
	 * \param parameters Les param�tres du GameObject
	 */
	virtual void load(const LoadParameters *parameters) {
		position = Vector2D(parameters->getX(), parameters->getY());
		velocity = acceleration = Vector2D(0,0);

		sprite = new Sprite(parameters->getTextureID());
	}

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
	Vector2D & getPosition() {return position;}

	/**
	 * \brief Positionne le GameObject
	 * \param newPosition La nouvelle position du GameObject
	 */
	void setPosition(Vector2D newPosition) { position = newPosition; }

	/**
	 * \brief Positionne le GameObject
	 * \param new_x La nouvelle position en X
	 * \param new_y La nouvelle position en Y
	 */
	void setPosition(float new_x, float new_y) {
		position.x = new_x; position.y = new_y;
	}

	/**
	 * \brief D�finie la v�locit� du GameObject
	 * \param new_velocity La nouvelle v�locit�
	 */
	void setVelocity(Vector2D new_velocity) { velocity = new_velocity;}

	/**
	 * \brief D�finie la v�locit� du GameObject
	 * \param new_x La nouvelle v�locit� en X
	 * \param new_y La nouvelle v�locit� en Y
	 */
	void setVelocity(float new_x, float new_y) {
		velocity.x = new_x; velocity.y = new_y;
	}

	/**
	 * \brief D�finie l'angle du sprite (en degr�s)
	 * \param new_angle Le nouvelle angle du sprite
	 */
	void setSpriteAngle(float new_angle) const {
		sprite->setAngle(new_angle);
	}
	
	/**
	 * \brief D�termine si le GameObject est dedans ou en dehors des fronti�res de l'�cran de jeu.
	 * \return Vrai si il est dehors, faux sinon.
	 */
	bool isOutsideScreenBondaries() const;

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


	Sprite * getSprite() const {return sprite;}

	/**
	 * \brief Permet de savoir si le GameObject est mort ou non
	 * \return Vrai s'il est mort, faux sinon
	 */
	bool isDead() const {return is_dead;}
	
	/**
	 * \brief Retourne le SDL_Rect du sprite
	 */
	SDL_Rect getRect() const {
		SDL_Rect tmp_rect;

		tmp_rect.x = static_cast<int>(position.x);
		tmp_rect.y = static_cast<int>(position.y);
		tmp_rect.w = static_cast<int>(sprite->getWidth());
		tmp_rect.h = static_cast<int>(sprite->getHeight());

		return tmp_rect;
	}

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

