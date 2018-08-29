#pragma once
#include "Layer.h"
#include <vector>
#include "GameObject.h"

/**
 * \brief L'ObjectLayer représente les GameObjects stockés dans un layer.
 */
class ObjectLayer :
	public Layer {
public:
	/**
	 * \brief Affiche les tiles du layer.
	 */
	void update() override;

	/**
	 * \brief Mets à jour la position des tiles à afficher du layer.
	 */
	void render() override;

	/**
	 * \brief Retourne la liste des gameobjects présent sur le niveau.
	 * \return La liste des gameobjects présent sur le niveau.
	 */
	std::vector<GameObject*> * getGameObjects() { return &_gameobjects;}

private:
	/**
	 * \brief La liste des gameobjects présent sur le niveau.
	 */
	std::vector<GameObject*> _gameobjects;
};

