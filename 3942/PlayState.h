#pragma once
#include "GameState.h"
#include <vector>

#include "PlayerManager.h"
#include "UIManager.h"
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
	std::string getStateID() const override;

	/**
	 * \brief Mets � jour les informations des vagues et fait apparaitre les ennemis
	 */
	void waveUpdate();

	PlayState() = default;
	~PlayState() = default;
	 
private:

	/**
	 * \brief D�termine si le niveau est termin� ou non
	 */
	bool isLevelFinished();

	/**
	 * \brief l'ID de l'�tat.
	 */
	static const std::string play_id;

	/**
	 * \brief Informations concernant les vagues d'enemies
	 */
	std::vector<EnemySpawInformations> enemy_spaw_informations;

	/**
	 * \brief Le PlayerManager
	 */
	PlayerManager player_manager{};

	/**
	 * \brief L'UIManager
	 */
	UIManager ui_manager{};

	/**
	 * \brief Le timer pour l'appartion de vagues ennemies
	 */
	unsigned int timer{0};

	/**
	 * \brief Le compteur d'ennemis cr��s
	 */
	unsigned int encouter{0};
};

