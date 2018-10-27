#pragma once
#include <string>

/**
 * \brief G�re les background des sc�nes
 */
class Background {
public:
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

	/**
	 * \brief Mets � jour le background
	 */
	void update();

	/**
	 * \brief Nettoie le background
	 */
	void clean() const;

	Background() = default;
	~Background() = default;

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
	 * \brief Bool�en permettant de d�terminer si un background a �t� charg� ou non.
	 */
	bool is_loaded{false};

	/**
	 * \brief l'offset par rapport au haut de l'�cran de jeu.
	 */
	float offset;
};

