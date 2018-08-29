#pragma once

#include "LoadParameters.h"

/**
 * \brief Représente un objet du jeu. 
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
	 * \brief Mets à jour l'objet.
	 */
	virtual void update() = 0;

	/**
	 * \brief Libère la mémoire de cet objet.
	 */
	virtual void clean() = 0;


	/**
	 * \brief Charge les paramètres du GameObject
	 * \param parameters Les paramètres du GameObject
	 */
	virtual void load(const LoadParameters *parameters) = 0;

};
