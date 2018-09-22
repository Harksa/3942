#pragma once
#include <vector>
#include <utility>
#include "Enemy.h"

/**
 * \brief Les informations des vagues ennemies
 */
struct EnemySpawInformations {
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
	std::string textureID;

	/**
	 * \brief Constructeur
	 */
	EnemySpawInformations(std::string enemy, const float x, const float y, const int h, const unsigned int p, const unsigned int t, std::string texture) : type{std::move(enemy)}, spawn_x{x}, spawn_y{y}, health{h}, points{p}, timer{t}, textureID{std::move(texture)} {}
};

/**
 * \brief La classe permettant de génerer l'informations des vagues ennemis
 */
class WaveGenerator {
public:

	/**
	 * \brief Créer une vague en fonction du fichier rentré en paramètre
	 * \param fileName Le fichier où sont stockées les informations des vagues
	 * \param enemy_spaw_informations Le vecteur où seront stockés les informations tirées du fichier
	 */
	static void parseWave(const std::string& fileName, std::vector<EnemySpawInformations> * enemy_spaw_informations);

};

