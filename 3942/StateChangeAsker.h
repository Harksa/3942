#pragma once

/**
 * \brief Le choix de l'état où l'on souhaiter se rendre.
 */
enum StateChoice {
	MAIN_MENU,
	PLAY,
	PAUSE,
	GAME_OVER,
	RECONNECT_JOYSTICK
};

/**
 * \brief Fait la demande de changement d'état.
 */
class StateChangeAsker {
public:

	/**
	 * \brief Demande de changer d'état
	 * \param newChoice Le nouveau choix d'état
	 */
	static void askToChange(StateChoice newChoice) {
		choice = newChoice;
		is_asking_to_change = true;
	}

	/**
	 * \brief Demande de push un nouvelle état.
	 * \param newChoice Le nouveau choix d'état
	 */
	static void askToPush(StateChoice newChoice) {
		choice = newChoice;
		is_asking_to_push = true;
	}

	/**
	 * \brief Demande de popback du dernier état
	 */
	static void askForPopBack() {
		is_asking_for_popback = true;
	}

	/**
	 * \brief Réinitialise les paramètres
	 */
	static void reset() {
		is_asking_to_change = false;
		is_asking_for_popback = false;
		is_asking_to_push = false;
	};


	/**
	 * \brief Retourne le choix de l'état
	 * \return Le choix de l'état
	 */
	static StateChoice getChoice() { return choice;}

	/**
	 * \brief Permet de savoir si un changement d'état a été demandé
	 * \return Vrai si un changement a été demandé, faux sinon.
	 */
	static bool isAskingToChange() {return is_asking_to_change;}
	
	/**
	 * \brief Permet de savoir si une demande de push a été faite
	 * \return Vrai si une demande a été faite, faux sinon
	 */
	static bool isAskingToPush() { return is_asking_to_push;}

	/**
	 * \brief Permet de savoir si une demande de pop a été demandé
	 * \return Vrai si une demande a été faite, faux sinon
	 */
	static bool isAskingForPopBack() { return is_asking_for_popback;}

	/**
	 * \brief Permet de savoir si n'importe quel demande de changement dans les état a été faite
	 * \return Vrai si une demande a été faite, faux sinon
	 */
	static bool isAskingForAnyChanges() {
		return is_asking_to_change || is_asking_to_push || is_asking_for_popback;
	}

private:
	/**
	 * \brief Le choix de l'état où l'on souhaite se rendre
	 */
	static StateChoice choice;

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