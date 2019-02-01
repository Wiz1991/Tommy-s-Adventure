#include "Game.h"



Game::Game() : window(sf::VideoMode(800, 600), "Tommy's Adventure")
{


}




void Game::Update(sf::Time dT)
{
	//Update the current state
	mStateManager.Update(dT);
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (window.isOpen()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			proccesEvents();
			Update(timePerFrame);
		}
		Render();
	}
}

void Game::proccesEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		else 
			mStateManager.processEvents(event);
		
	}
}

void Game::Render()
{
	window.clear(sf::Color::White);
	//go thorugh all drawable objects and have them draw themself // Draw() { player.draw(), enemy.draw()...
	window.display();
}
