#pragma once
#include <vector>
#include <utility>
#include "Enemy.h"

/**
 * \brief Les informations des vagues ennemies
 */
struct EnemySpawInformations {
	/**
	 * \brief Le type d'ennemie qui sera cr��
	 */
	std::string type;

	/**
	 * \brief La position en x o� il sera cr��
	 */
	float spawn_x;

	/**
	 * \brief La position en Y o� il sera cr��
	 */
	float spawn_y;

	/**
	 * \brief La vie de cet unit�
	 */
	int health;

	/**
	 * \brief Les points donn�es par l'unit� lorsqu'elle meurt
	 */
	unsigned int points;

	/**
	 * \brief Le temps o� il sera cr��
	 */
	unsigned int timer;

	/**
	 * \brief La texture assign� � cet ennemi
	 */
	std::string textureID;

	/**
	 * \brief Constructeur
	 */
	EnemySpawInformations(std::string enemy, const float x, const float y, const int h, const unsigned int p, const unsigned int t, std::string texture) : type{std::move(enemy)}, spawn_x{x}, spawn_y{y}, health{h}, points{p}, timer{t}, textureID{std::move(texture)} {}
};

/**
 * \brief La classe permettant de g�nerer l'informations des vagues ennemis
 */
class WaveGenerator {
public:

	/**
	 * \brief Cr�er une vague en fonction du fichier rentr� en param�tre
	 * \param fileName Le fichier o� sont stock�es les informations des vagues
	 * \param enemy_spaw_informations Le vecteur o� seront stock�s les informations tir�es du fichier
	 */
	static void parseWave(const std::string& fileName, std::vector<EnemySpawInformations> * enemy_spaw_informations);

};

