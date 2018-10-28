#include "StateChangeAsker.h"

StateChoice StateChangeAsker::choice{MAIN_MENU};

bool StateChangeAsker::is_asking_to_change{false};

bool StateChangeAsker::is_asking_for_popback{false};

bool StateChangeAsker::is_asking_to_push{false};

bool StateChangeAsker::has_won{false};

unsigned int StateChangeAsker::current_level{1};

void StateChangeAsker::askToChange(StateChoice new_choice) {
	choice = new_choice;
	is_asking_to_change = true;
}

void StateChangeAsker::askToPush(StateChoice new_choice) {
	choice = new_choice;
	is_asking_to_push = true;
}

void StateChangeAsker::askForPopBack() {
	is_asking_for_popback = true;
}

void StateChangeAsker::reset() {
	is_asking_to_change = false;
	is_asking_for_popback = false;
	is_asking_to_push = false;
}

StateChoice StateChangeAsker::getChoice() { return choice; }

bool StateChangeAsker::isAskingToChange() { return is_asking_to_change; }

bool StateChangeAsker::isAskingToPush() { return is_asking_to_push; }

bool StateChangeAsker::isAskingForPopBack() { return is_asking_for_popback; }

bool StateChangeAsker::isAskingForAnyChanges() {
	return is_asking_to_change || is_asking_to_push || is_asking_for_popback;
}

void StateChangeAsker::incrementeLevel() { current_level++; }

unsigned StateChangeAsker::getCurrentLevel() { return current_level; }

void StateChangeAsker::setHasWon(bool value) { has_won = value; }

bool StateChangeAsker::hasWonTheGame() { return has_won; }
