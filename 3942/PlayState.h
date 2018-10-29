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
	std::string getStateID() const override;

	/**
	 * \brief Mets à jour les informations des vagues et fait apparaitre les ennemis
	 */
	void waveUpdate();

	PlayState() = default;
	~PlayState() = default;
	 
private:

	/**
	 * \brief Détermine si le niveau est terminé ou non
	 */
	bool isLevelFinished();

	/**
	 * \brief l'ID de l'état.
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
	 * \brief Le compteur d'ennemis créés
	 */
	unsigned int encouter{0};
};

