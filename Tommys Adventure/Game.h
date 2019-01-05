#pragma once
#include <SFML/Graphics.hpp>
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



};

