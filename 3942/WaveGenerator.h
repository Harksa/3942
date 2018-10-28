#pragma once
#include <vector>
#include "Enemy.h"

/**
 * \brief Les informations des vagues ennemies
 */
struct EnemySpawInformations {

	/**
	 * \brief Constructeur
	 * \param pEnemyType Le type d'enemie � cr�er
	 * \param pX Sa position en X
	 * \param pY Sa position en Y
	 * \param pHealth Sa vie
	 * \param pPoints Le nombre de points attribu�s � sa mort
	 * \param pTimer Le temps � laquel il apparait
	 * \param pTexture La texture associ� � l'ennemi 
	 */
	EnemySpawInformations(std::string pEnemyType, float pX, float pY, int pHealth, unsigned int pPoints,
	                      unsigned int pTimer, std::string pTexture);

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
	std::string texture_id;

};

/**
 * \brief La classe permettant de g�nerer l'informations des vagues ennemis
 */
class WaveGenerator {
public:

	/**
	 * \brief Cr�er une vague en fonction du fichier rentr� en param�tre
	 * \param pFileName Le fichier o� sont stock�es les informations des vagues
	 * \param pEnemySpawInformations Le vecteur o� seront stock�s les informations tir�es du fichier
	 */
	static void parseWave(const std::string& pFileName, std::vector<EnemySpawInformations> * pEnemySpawInformations);

};

