#pragma once
#include "State.h"

class Menu : public State
{
public:
	Menu() : State(State::Type::MENU) {}
	
	void Update(sf::Time dT)override;
	void processEvents(sf::Event event)override;
	void draw()override;
	void print() { puts("YES"); }
};

