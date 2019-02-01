#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"
class Game
{
public:
	Game();
public:
	void Update(sf::Time dT);
	void Run();
	void proccesEvents();
	void Render();
private:
	sf::RenderWindow window;
        StateManager mStateManager;


};

