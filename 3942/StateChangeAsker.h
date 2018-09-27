#pragma once

/**
 * \brief Le choix de l'�tat o� l'on souhaiter se rendre.
 */
enum StateChoice {
	MAIN_MENU,
	PLAY,
	PAUSE,
	GAME_OVER,
	RECONNECT_JOYSTICK
};

/**
 * \brief Fait la demande de changement d'�tat.
 */
class StateChangeAsker {
public:

	/**
	 * \brief Demande de changer d'�tat
	 * \param newChoice Le nouveau choix d'�tat
	 */
	static void askToChange(StateChoice newChoice) {
		choice = newChoice;
		is_asking_to_change = true;
	}

	/**
	 * \brief Demande de push un nouvelle �tat.
	 * \param newChoice Le nouveau choix d'�tat
	 */
	static void askToPush(StateChoice newChoice) {
		choice = newChoice;
		is_asking_to_push = true;
	}

	/**
	 * \brief Demande de popback du dernier �tat
	 */
	static void askForPopBack() {
		is_asking_for_popback = true;
	}

	/**
	 * \brief R�initialise les param�tres
	 */
	static void reset() {
		is_asking_to_change = false;
		is_asking_for_popback = false;
		is_asking_to_push = false;
	};


	/**
	 * \brief Retourne le choix de l'�tat
	 * \return Le choix de l'�tat
	 */
	static StateChoice getChoice() { return choice;}

	/**
	 * \brief Permet de savoir si un changement d'�tat a �t� demand�
	 * \return Vrai si un changement a �t� demand�, faux sinon.
	 */
	static bool isAskingToChange() {return is_asking_to_change;}
	
	/**
	 * \brief Permet de savoir si une demande de push a �t� faite
	 * \return Vrai si une demande a �t� faite, faux sinon
	 */
	static bool isAskingToPush() { return is_asking_to_push;}

	/**
	 * \brief Permet de savoir si une demande de pop a �t� demand�
	 * \return Vrai si une demande a �t� faite, faux sinon
	 */
	static bool isAskingForPopBack() { return is_asking_for_popback;}

	/**
	 * \brief Permet de savoir si n'importe quel demande de changement dans les �tat a �t� faite
	 * \return Vrai si une demande a �t� faite, faux sinon
	 */
	static bool isAskingForAnyChanges() {
		return is_asking_to_change || is_asking_to_push || is_asking_for_popback;
	}

private:
	/**
	 * \brief Le choix de l'�tat o� l'on souhaite se rendre
	 */
	static StateChoice choice;

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