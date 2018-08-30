#pragma once
#include <string>

/**
 * \brief G�re les background des sc�nes
 */
class Background {
public:
	Background() = default;
	~Background() = default;

	/**
	 * \brief Charge l'image du background
	 * \param fileName L'emplacement du fichier
	 * \param id l'ID de la texture
	 * \param speed Vitesse de d�placement du background. 0 par d�faut si le background ne bouge pas.
	 */
	bool load(const std::string& fileName, const std::string& id, float speed = 0);

	/**
	 * \brief Affiche le background
	 */
	void draw();

	void clean() const;

private:
	/**
	 * \brief Affiche un background statique
	 */
	void drawStatic() const;

	/**
	 * \brief Affiche un background anim�
	 */
	void drawMoving();

	/**
	 * \brief L'ID du background
	 */
	std::string backgroundID;

	/**
	 * \brief Vitesse de d�placement du background
	 */
	float movingSpeed;

	/**
	 * \brief l'offset par rapport au haut de l'�cran de jeu.
	 */
	float offset;
};

