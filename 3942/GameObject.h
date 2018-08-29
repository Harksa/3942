#pragma once

#include "LoadParameters.h"

/**
 * \brief Repr�sente un objet du jeu. 
 */
class GameObject {
public:
	GameObject() = default;
	virtual ~GameObject() = default;

	/**
	 * \brief Affiche l'objet.
	 */
	virtual void draw() = 0;

	/**
	 * \brief Mets � jour l'objet.
	 */
	virtual void update() = 0;

	/**
	 * \brief Lib�re la m�moire de cet objet.
	 */
	virtual void clean() = 0;


	/**
	 * \brief Charge les param�tres du GameObject
	 * \param parameters Les param�tres du GameObject
	 */
	virtual void load(const LoadParameters *parameters) = 0;

};
