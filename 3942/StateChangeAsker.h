#pragma once

/**
 * \brief Le choix de l'�tat o� l'on souhaiter se rendre.
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
 * \brief Fait la demande de changement d'�tat.
 */
class StateChangeAsker {
public:

	/**
	 * \brief Demande de changer d'�tat
	 * \param pNewChoice Le nouveau choix d'�tat
	 */
	static void askToChange(StateChoice pNewChoice);

	/**
	 * \brief Demande de push un nouvelle �tat.
	 * \param pNewChoice Le nouveau choix d'�tat
	 */
	static void askToPush(StateChoice pNewChoice);

	/**
	 * \brief Demande de popback du dernier �tat
	 */
	static void askForPopBack();

	/**
	 * \brief R�initialise les param�tres
	 */
	static void reset();;


	/**
	 * \brief Retourne le choix de l'�tat
	 * \return Le choix de l'�tat
	 */
	static StateChoice getChoice();

	/**
	 * \brief Permet de savoir si un changement d'�tat a �t� demand�
	 * \return Vrai si un changement a �t� demand�, faux sinon.
	 */
	static bool isAskingToChange();

	/**
	 * \brief Permet de savoir si une demande de push a �t� faite
	 * \return Vrai si une demande a �t� faite, faux sinon
	 */
	static bool isAskingToPush();

	/**
	 * \brief Permet de savoir si une demande de pop a �t� demand�
	 * \return Vrai si une demande a �t� faite, faux sinon
	 */
	static bool isAskingForPopBack();

	/**
	 * \brief Permet de savoir si n'importe quel demande de changement dans les �tat a �t� faite
	 * \return Vrai si une demande a �t� faite, faux sinon
	 */
	static bool isAskingForAnyChanges();

	/**
	 * \brief Incr�mente le niveau actuel
	 */
	static void incrementeLevel();

	/**
	 * \brief Retourne le niveau actuel
	 */
	static unsigned int getCurrentLevel();

	/**
	 * \brief Permet de parametrer la fin de jeu, selon si les joueur a gagn�s ou perdu
	 * \param pValue Vrai si le joueur a gagn�, faux sinon
	 */
	static void setHasWon(bool pValue);

	/**
	 * \brief Retourne la valeur permettant de savoir si les joueurs ont gagn�s ou non
	 * \return Vrai si les joueurs ont gagn�s, faux sinon
	 */
	static bool hasWonTheGame();

private:
	/**
	 * \brief Le choix de l'�tat o� l'on souhaite se rendre
	 */
	static StateChoice choice;

	/**
	 * \brief Le niveau courant
	 */
	static unsigned int current_level;

	/**
	 * \brief Permet de d�terminer si le joueur � gagn� le jeu ou non.
	 */
	static bool has_won;

	/**
	 * \brief bool�en d�terminant si une demande de changement a �t� effectu�
	 */
	static bool is_asking_to_change;

	/**
	 * \brief Bool�en d�terminant si une demande de push a �t� effectu�
	 */
	static bool is_asking_to_push;

	/**
	 * \brief Bool�en d�terminant si une demande de popback a �t� effectu�
	 */
	static bool is_asking_for_popback;

};