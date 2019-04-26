#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include <SFML/Graphics/Text.hpp>
#include "SFML/System/Time.hpp"
#include <SFML/Graphics/Font.hpp>
#include "World.h"
#include "Player.h"
#include "Utilities.h"


class Game
{
public:
	Game();
	void Run();
	void Update(sf::Time dT);
	void Render();
	void processEvents();
	void updateStatistics(sf::Time timeElapsed);

private:
	sf::RenderWindow mWindow;
	World mWorld;
	sf::Font mFont;
	size_t mStatisticsFrames;
	sf::Time mUpdateTime;
	sf::Text mStatisticsText;
	Player mPlayer;
};
