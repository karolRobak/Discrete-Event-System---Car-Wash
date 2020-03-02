#include<string>
#include<list>
#include<iostream>
#include"transition.h"
#include"State.h"
#include<cstring>
#ifndef AUTOMATA_H_
#define AUTOMATA_H_
#define NUMBER_OF_STATES 100
#define NUMBER_OF_TRANSITIONS 120
class Automata {
	std::string name;
	short automataID;
	State states[NUMBER_OF_STATES];
	Transition transitions[NUMBER_OF_TRANSITIONS];
	int currentState;
	std::string currentStateName;
public:
	Automata();
	Automata(std::string name);
	void setID(short id);
	void setName(std::string name);
	void addStatesFrom(State setOfAutomataStates[]);
	void addTransitionFrom(Transition setOfTransitions[]);
	void checkCurrentStateName();
	void printNameAndCurrentState();
	void showAvailableTransitions();
	void performTransition(int transitionID);
};
#endif

