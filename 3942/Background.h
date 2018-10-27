#pragma once
#include <string>

/**
 * \brief Gère les background des scènes
 */
class Background {
public:
	/**
	 * \brief Charge l'image du background
	 * \param fileName L'emplacement du fichier
	 * \param id l'ID de la texture
	 * \param speed Vitesse de déplacement du background. 0 par défaut si le background ne bouge pas.
	 */
	bool load(const std::string& fileName, const std::string& id, float speed = 0);

	/**
	 * \brief Affiche le background
	 */
	void draw();

	/**
	 * \brief Mets à jour le background
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
	 * \brief Affiche un background animé
	 */
	void drawMoving();

	/**
	 * \brief L'ID du background
	 */
	std::string backgroundID;

	/**
	 * \brief Vitesse de déplacement du background
	 */
	float movingSpeed;

	/**
	 * \brief Booléen permettant de déterminer si un background a été chargé ou non.
	 */
	bool is_loaded{false};

	/**
	 * \brief l'offset par rapport au haut de l'écran de jeu.
	 */
	float offset;
};

