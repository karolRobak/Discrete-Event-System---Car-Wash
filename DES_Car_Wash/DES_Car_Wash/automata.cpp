#include "automata.h"
Automata::Automata() {}
Automata::Automata(std::string name) {
	this->name = name;
}
void Automata::setID(short id) {
	this->automataID = id;
}
void Automata::setName(std::string name) {
	this->name = name;
}
void Automata::printNameAndCurrentState() {
	std::cout << "Automata: " << name << " State: ";
	this->checkCurrentStateName();
	std::cout << currentStateName;
	std::cout << " " << std::endl;
}
void Automata::checkCurrentStateName() {
	for (short i = 0; i <= NUMBER_OF_STATES; i++) {
		if (states[i].stateID == currentState) {
			currentStateName = states[i].name;
		}
	}
}
void Automata::showAvailableTransitions() {
	std::cout << "Available transitions: "<<std::endl;
	for (short i = 0; i <= NUMBER_OF_TRANSITIONS; i++) {
		if (transitions[i].currentStateID == currentState) {
			std::cout << " [ ] "<<transitions[i].transitionName << " (" << transitions[i].transitionID << ") " << std::endl;
		}
	}
	std::cout << " " << std::endl;
}
void Automata::addStatesFrom(State setOfAutomataStates[]) {
	short p = 0;
	for (short i = 0; i < NUMBER_OF_STATES; i++) {
		if (setOfAutomataStates[i].automataID == this->automataID &&
			!setOfAutomataStates[i].name.empty()) {
			states[p].automataID = setOfAutomataStates[i].automataID;
			states[p].stateID = setOfAutomataStates[i].stateID;
			states[p].name = setOfAutomataStates[i].name;
			p++;
		}
	}
	currentState = states[0].stateID;
}
void Automata::addTransitionFrom(Transition setOfTransitions[]) {
	short p = 0;
	for (short i = 0; i < NUMBER_OF_TRANSITIONS; i++) {
		if (setOfTransitions[i].automataID == this->automataID &&
			setOfTransitions[i].transitionID>0) {
			transitions[p].automataID = this->automataID;
			transitions[p].currentStateID = setOfTransitions[i].currentStateID;
			transitions[p].nextStateID = setOfTransitions[i].nextStateID;
			transitions[p].transitionID = setOfTransitions[i].transitionID;
			transitions[p].transitionName = setOfTransitions[i].transitionName;
			p++;
		}
	}
}

void Automata::performTransition(int transitionID) {
	for (short i = 0; i < NUMBER_OF_TRANSITIONS; i++) {
		if (transitions[i].currentStateID == currentState &&
			transitions[i].transitionID == transitionID) {
			currentState = transitions[i].nextStateID;
			checkCurrentStateName();
		}
	}
}