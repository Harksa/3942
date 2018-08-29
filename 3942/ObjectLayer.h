#pragma once
#include "Layer.h"
#include <vector>
#include "GameObject.h"

/**
 * \brief L'ObjectLayer repr�sente les GameObjects stock�s dans un layer.
 */
class ObjectLayer :
	public Layer {
public:
	/**
	 * \brief Affiche les tiles du layer.
	 */
	void update() override;

	/**
	 * \brief Mets � jour la position des tiles � afficher du layer.
	 */
	void render() override;

	/**
	 * \brief Retourne la liste des gameobjects pr�sent sur le niveau.
	 * \return La liste des gameobjects pr�sent sur le niveau.
	 */
	std::vector<GameObject*> * getGameObjects() { return &_gameobjects;}

private:
	/**
	 * \brief La liste des gameobjects pr�sent sur le niveau.
	 */
	std::vector<GameObject*> _gameobjects;
};

