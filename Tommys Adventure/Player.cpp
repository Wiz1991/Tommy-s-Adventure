#include "Player.h"

void Player::handleEvents(sf::Event& event, CommandQueue& commands)
{
	if(event.key.code)
}

void Player::handleRealTimeInput(const sf::Event& event, CommandQueue& commands)
{
	const float playerSpeed = 40.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		Command moveUp;
		moveUp.category = Category::PlayerAircraft;
		moveUp.action = derivedAction<Airplane>(AircraftMover(0, -playerSpeed));
		commands.push(moveUp);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		Command moveDown;
		moveDown.category = Category::PlayerAircraft;
		moveDown.action = derivedAction<Airplane>(AircraftMover(0, playerSpeed));
		commands.push(moveDown);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Airplane>(AircraftMover(-playerSpeed,0));
		commands.push(moveLeft);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		Command moveRight;
		moveRight.category = Category::PlayerAircraft;
		moveRight.action = derivedAction<Airplane>(AircraftMover(playerSpeed, 0));
		commands.push(moveRight);
	}




}
