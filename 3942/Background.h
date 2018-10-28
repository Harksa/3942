#pragma once
#include <string>

/**
 * \brief Gère les background des scènes
 */
class Background {
public:
	/**
	 * \brief Charge l'image du background
	 * \param pFileName L'emplacement du fichier
	 * \param pId l'ID de la texture
	 * \param pSpeed Vitesse de déplacement du background. 0 par défaut si le background ne bouge pas.
	 */
	bool load(const std::string& pFileName, const std::string& pId, float pSpeed = 0);

	/**
	 * \brief Affiche le background
	 */
	void draw() const;

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
	void drawMoving() const;

	/**
	 * \brief L'ID du background
	 */
	std::string background_id;

	/**
	 * \brief Vitesse de déplacement du background
	 */
	float moving_speed;

	/**
	 * \brief Booléen permettant de déterminer si un background a été chargé ou non.
	 */
	bool is_loaded{false};

	/**
	 * \brief l'offset par rapport au haut de l'écran de jeu.
	 */
	float offset;
};

