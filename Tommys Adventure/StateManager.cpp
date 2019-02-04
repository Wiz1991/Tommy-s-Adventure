#include "Statemanager.h"
#include "CommonStates.h"
#include <iostream>

StateManager::StateManager() : mCurrentState(static_cast<int>(State::Type::MENU)), mIsRunning(true) {
	RegisterStates();
}
StateManager::~StateManager() {
	
}

void StateManager::RegisterStates()
{
	for (int i = 0; i < static_cast<int>(State::Type::TOTAL); ++i)
	{
		mStateStack.push_back(GetStateFromType(static_cast<State::Type>(i)));

		if (mStateStack.at(i) == nullptr)
			std::cout << "Error! Null pointer pushed onto state stack." << std::endl;
	}
}

void StateManager::ClearStateStack()
{
	for (int i = 0; i < static_cast<int>(State::Type::TOTAL); ++i) {
		delete mStateStack.at(i);
	}
}

bool StateManager::isEmpty()
{
	return mStateStack.empty();
}


void StateManager::Update(sf::Time dT)
{
	mStateStack[mCurrentState]->Update(dT);
	State::Type myNextState = mStateStack[mCurrentState]->GetNextState();
	State::Type myCurrentState = static_cast<State::Type>(mCurrentState);
	if (myCurrentState == State::Type::GAME_OVER)
		mIsRunning = false;
	if (myCurrentState != myNextState)
	{
		mCurrentState = static_cast<int>(myNextState);

	}
}

void StateManager::handleEvents(sf::Event event)
{
	mStateStack[mCurrentState]->processEvents(event);
}

void StateManager::draw()
{
}
