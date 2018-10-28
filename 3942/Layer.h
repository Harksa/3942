#pragma once

/**
 * \brief Représente un layer dans Tiled.
 */
class Layer {
public:
	/**
	 * \brief Affiche les tiles du layer.
	 */
	virtual void render() = 0;

	/**
	 * \brief Mets à jour la position des tiles à afficher du layer.
	 */
	virtual void update() = 0;

protected:
	virtual ~Layer() = default;
};