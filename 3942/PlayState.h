#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "Level.h"
#include "WaveGenerator.h"

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

	void waveUpdate();

private:

	/**
	 * \brief l'ID de l'�tat.
	 */
	static const std::string playID;

	std::vector<EnemySpawInformations *> enemy_spaw_informations;

	unsigned int timer;

	unsigned int encouter;

};

