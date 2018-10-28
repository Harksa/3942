#pragma once

/**
 * \brief Repr�sente un layer dans Tiled.
 */
class Layer {
public:
	/**
	 * \brief Affiche les tiles du layer.
	 */
	virtual void render() = 0;

	/**
	 * \brief Mets � jour la position des tiles � afficher du layer.
	 */
	virtual void update() = 0;

protected:
	virtual ~Layer() = default;
};