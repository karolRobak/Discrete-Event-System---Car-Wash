#ifndef TRANSITION_H_
#define TRANSITION_H_
#include<string>
struct Transition
{
	int automataID;
	int currentStateID;
	std::string transitionName;
	int transitionID;
	int nextStateID;
};
#endif
