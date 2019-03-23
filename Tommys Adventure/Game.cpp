#include "Game.h"


Game::Game() 
	: mWindow(sf::VideoMode(640, 480), "Animations"),
      mWorld(mWindow)
{}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while(mWindow.isOpen())
	{
		sf::Time dT = clock.restart();
		timeSinceLastUpdate += dT;
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			Update(timePerFrame);
		}
	Render();
	}

}

void Game::Update(sf::Time dT)
{
	mWorld.update(dT);
}

void Game::Render()
{
	mWindow.clear(sf::Color::White);
	mWorld.draw();
	mWindow.display();
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			mWindow.close();




	}
	
}

