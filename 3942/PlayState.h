#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Level.h"
#include "WaveGenerator.h"
#include "BulletManager.h"

/**
 * \brief Etat de jeu.
 */
class PlayState :
	public GameState {
public:
	/**
	 * \brief Mets à jour l'état.
	 */
	void update() override;

	/**
	 * \brief Affiche l'état.
	 */
	void render() override;

	/**
	 * \brief Actions effectuées lors de l'entré dans cet état.
	 */
	bool onEnter() override;

	/**
	 * \brief Actions effectuées lors de la sortie de cet état.
	 */
	bool onExit() override;

	/**
	 * \brief Retourne l'ID de l'état
	 * \return l'ID de l'état.
	 */
	std::string getStateID() const override {return playID;}

	void waveUpdate();

private:

	/**
	 * \brief l'ID de l'état.
	 */
	static const std::string playID;

	std::vector<EnemySpawInformations *> enemy_spaw_informations;

	BulletManager * bulletManager;

	unsigned int timer = 0;

	unsigned int encouter = 0;

};

