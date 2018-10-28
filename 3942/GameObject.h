#pragma once
#include "LoadParameters.h"
#include "Sprite.h"
#include "Vector2D.h"

/**
 * \brief La classe qui permet de gérer les éléments graphiques du jeu.
 */
class GameObject {
public:
	/**
	 * \brief Charge le GameObject en fonction du LoadParameters
	 * \param pParameters Les paramètres du GameObject
	 */
	virtual void load(const LoadParameters* pParameters);

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
	 * \param pNewPosition La nouvelle position du GameObject
	 */
	void setPosition(Vector2D pNewPosition);

	/**
	 * \brief Positionne le GameObject
	 * \param pNewX La nouvelle position en X
	 * \param pNewY La nouvelle position en Y
	 */
	void setPosition(float pNewX, float pNewY);

	/**
	 * \brief Définie la vélocité du GameObject
	 * \param pNewVelocity La nouvelle vélocité
	 */
	void setVelocity(Vector2D pNewVelocity);

	/**
	 * \brief Définie la vélocité du GameObject
	 * \param pNewX La nouvelle vélocité en X
	 * \param pNewY La nouvelle vélocité en Y
	 */
	void setVelocity(float pNewX, float pNewY);

	/**
	 * \brief Définie l'angle du sprite (en degrès)
	 * \param pNewAngle Le nouvelle angle du sprite
	 */
	void setSpriteAngle(float pNewAngle) const;

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

	/**
	 * \brief Retourne le sprite
	 * \return Le sprite
	 */
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

