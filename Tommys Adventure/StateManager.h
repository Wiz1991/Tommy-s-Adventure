#pragma once
#include <vector>
#include "State.h"


class StateManager
{
public:
	StateManager();
	~StateManager();
	void RegisterStates();
	void ClearStateStack();
	bool isEmpty();

	void Update(sf::Time dT);
	void handleEvents(sf::Event event);
	void draw();


private:
	std::vector<State*> mStateStack;
	int mCurrentState;
	bool mIsRunning;
};