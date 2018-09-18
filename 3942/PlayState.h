#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "Level.h"
#include "WaveGenerator.h"
#include "BulletManager.h"
#include "Player.h"

/**
 * \brief Etat de jeu.
 */
class PlayState :
	public GameState {
public:
	/**
	 * \brief Mets � jour l'�tat.
	 */
	void update() override;

	/**
	 * \brief Affiche l'�tat.
	 */
	void render() override;

	/**
	 * \brief Actions effectu�es lors de l'entr� dans cet �tat.
	 */
	bool onEnter() override;

	/**
	 * \brief Actions effectu�es lors de la sortie de cet �tat.
	 */
	bool onExit() override;

	/**
	 * \brief Retourne l'ID de l'�tat
	 * \return l'ID de l'�tat.
	 */
	std::string getStateID() const override {return playID;}

	/**
	 * \brief Mets � jour les informations des vagues et fait apparaitre les ennemis
	 */
	void waveUpdate();

	PlayState() = default;
	~PlayState() = default;
	 
private:

	/**
	 * \brief l'ID de l'�tat.
	 */
	static const std::string playID;

	/**
	 * \brief Informations concernant les vagues d'enemies
	 */
	std::vector<EnemySpawInformations *> enemy_spaw_informations;

	/**
	 * \brief Le timer pour l'appartion de vagues ennemies
	 */
	unsigned int timer = 0;

	/**
	 * \brief Le compteur d'ennemis cr��s
	 */
	unsigned int encouter = 0;

	/**
	 * \brief Le joueur
	 */
	Player * player = nullptr;

};

