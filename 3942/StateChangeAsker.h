#pragma once

/**
 * \brief Le choix de l'état où l'on souhaiter se rendre.
 */
enum StateChoice {
	MAIN_MENU,
	CHOOSE_CONTROLS,
	OPTIONS,
	PLAY,
	PAUSE,
	GAME_OVER
};

/**
 * \brief Fait la demande de changement d'état.
 */
class StateChangeAsker {
public:

	/**
	 * \brief Demande de changer d'état
	 * \param pNewChoice Le nouveau choix d'état
	 */
	static void askToChange(StateChoice pNewChoice);

	/**
	 * \brief Demande de push un nouvelle état.
	 * \param pNewChoice Le nouveau choix d'état
	 */
	static void askToPush(StateChoice pNewChoice);

	/**
	 * \brief Demande de popback du dernier état
	 */
	static void askForPopBack();

	/**
	 * \brief Réinitialise les paramètres
	 */
	static void reset();;


	/**
	 * \brief Retourne le choix de l'état
	 * \return Le choix de l'état
	 */
	static StateChoice getChoice();

	/**
	 * \brief Permet de savoir si un changement d'état a été demandé
	 * \return Vrai si un changement a été demandé, faux sinon.
	 */
	static bool isAskingToChange();

	/**
	 * \brief Permet de savoir si une demande de push a été faite
	 * \return Vrai si une demande a été faite, faux sinon
	 */
	static bool isAskingToPush();

	/**
	 * \brief Permet de savoir si une demande de pop a été demandé
	 * \return Vrai si une demande a été faite, faux sinon
	 */
	static bool isAskingForPopBack();

	/**
	 * \brief Permet de savoir si n'importe quel demande de changement dans les état a été faite
	 * \return Vrai si une demande a été faite, faux sinon
	 */
	static bool isAskingForAnyChanges();

	/**
	 * \brief Incrèmente le niveau actuel
	 */
	static void incrementeLevel();

	/**
	 * \brief Retourne le niveau actuel
	 */
	static unsigned int getCurrentLevel();

	/**
	 * \brief Permet de parametrer la fin de jeu, selon si les joueur a gagnés ou perdu
	 * \param pValue Vrai si le joueur a gagné, faux sinon
	 */
	static void setHasWon(bool pValue);

	/**
	 * \brief Retourne la valeur permettant de savoir si les joueurs ont gagnés ou non
	 * \return Vrai si les joueurs ont gagnés, faux sinon
	 */
	static bool hasWonTheGame();

private:
	/**
	 * \brief Le choix de l'état où l'on souhaite se rendre
	 */
	static StateChoice choice;

	/**
	 * \brief Le niveau courant
	 */
	static unsigned int current_level;

	/**
	 * \brief Permet de déterminer si le joueur à gagné le jeu ou non.
	 */
	static bool has_won;

	/**
	 * \brief booléen déterminant si une demande de changement a été effectué
	 */
	static bool is_asking_to_change;

	/**
	 * \brief Booléen déterminant si une demande de push a été effectué
	 */
	static bool is_asking_to_push;

	/**
	 * \brief Booléen déterminant si une demande de popback a été effectué
	 */
	static bool is_asking_for_popback;

};