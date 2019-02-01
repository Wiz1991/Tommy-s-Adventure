#include "StateManager.h"
#include <SFML/Graphics.hpp>
StateManager::StateManager() : mCurrentStateIndetifier(static_cast<int>(State::States::INTRO))
{}


void StateManager::RegisterStates(){
 for(int i=0;i<static_cast<int>(State::States::TOTAL);i++){
   mStateStack.push_back(getStateFromType(static_cast<State::States>(i)));
 }
}

void StateManager::Update(sf::Time dT){
   mStateStack[mCurrentStateIndetifier]->Update();
   if(mCurrentState!=mNextState)
    mCurrentState
 
}

