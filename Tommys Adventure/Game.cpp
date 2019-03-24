#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Animations"),
	mWorld(mWindow),
	mFont(),
	mStatisticsFrames(0),
	mUpdateTime()
{
	mFont.loadFromFile("fonts/micross.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(15);
	mWindow.setFramerateLimit(60);
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (mWindow.isOpen())
	{
		sf::Time dT = clock.restart();
		timeSinceLastUpdate += dT;
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			Update(timePerFrame);
		}
		updateStatistics(dT);
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

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			mWindow.close();
		if (event.type == sf::Event::KeyPressed) {
			mWorld.handleInput(event.key.code);
		}
	}
}

void Game::updateStatistics(sf::Time timeElapsed)
{
	mUpdateTime += timeElapsed;
	mStatisticsFrames += 1;
	if (mUpdateTime >= sf::seconds(1.0f)) {
		mStatisticsText.setString("FPS: " + toString<float>(mStatisticsFrames));
		mUpdateTime -= sf::seconds(1.0f);
		mStatisticsFrames = 0;
	}
}