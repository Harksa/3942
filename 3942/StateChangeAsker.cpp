#include "StateChangeAsker.h"

StateChoice StateChangeAsker::choice = MAIN_MENU;

bool StateChangeAsker::is_asking_to_change = false;

bool StateChangeAsker::is_asking_for_popback = false;

bool StateChangeAsker::is_asking_to_push = false;