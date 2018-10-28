#pragma once
#include <vector>
#include "Enemy.h"

/**
 * \brief Les informations des vagues ennemies
 */
struct EnemySpawInformations {

	/**
	 * \brief Constructeur
	 * \param pEnemyType Le type d'enemie à créer
	 * \param pX Sa position en X
	 * \param pY Sa position en Y
	 * \param pHealth Sa vie
	 * \param pPoints Le nombre de points attribués à sa mort
	 * \param pTimer Le temps à laquel il apparait
	 * \param pTexture La texture associé à l'ennemi 
	 */
	EnemySpawInformations(std::string pEnemyType, float pX, float pY, int pHealth, unsigned int pPoints,
	                      unsigned int pTimer, std::string pTexture);

	/**
	 * \brief Le type d'ennemie qui sera créé
	 */
	std::string type;

	/**
	 * \brief La position en x où il sera créé
	 */
	float spawn_x;

	/**
	 * \brief La position en Y où il sera créé
	 */
	float spawn_y;

	/**
	 * \brief La vie de cet unité
	 */
	int health;

	/**
	 * \brief Les points données par l'unité lorsqu'elle meurt
	 */
	unsigned int points;

	/**
	 * \brief Le temps où il sera créé
	 */
	unsigned int timer;

	/**
	 * \brief La texture assigné à cet ennemi
	 */
	std::string texture_id;

};

/**
 * \brief La classe permettant de génerer l'informations des vagues ennemis
 */
class WaveGenerator {
public:

	/**
	 * \brief Créer une vague en fonction du fichier rentré en paramètre
	 * \param pFileName Le fichier où sont stockées les informations des vagues
	 * \param pEnemySpawInformations Le vecteur où seront stockés les informations tirées du fichier
	 */
	static void parseWave(const std::string& pFileName, std::vector<EnemySpawInformations> * pEnemySpawInformations);

};

