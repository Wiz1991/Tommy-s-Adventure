#include "Player.h"

Player::Player()
{
	initializeKeyBinds();
	initializeActions();
	//set categories
	for (auto& cat : mActionBind) {
		cat.second.category = Category::PlayerAircraft;
	}
}

void Player::assignKeybind(sf::Keyboard::Key key, Action action)
{
}

bool Player::isRealTimeAction(Action action)
{
	switch (action)
	{
	case moveRight:
	case moveLeft:
	case moveUp:
	case moveDown:
		return true;
	default:
		return false;
	}
}

void Player::handleEvents(sf::Event& event, CommandQueue& commands)
{
	if (event.key.code == sf::Keyboard::P) {
		Command positionAction;
		positionAction.category = Category::PlayerAircraft;
		positionAction.action = [](SceneNode & node, sf::Time dT) {
				std::cout << "PosX: " << node.getPosition().x << "\nPosY:" <<
					node.getPosition().y << "\n";
		};
		commands.push(positionAction);
	}

}

void Player::handleRealTimeInput(CommandQueue& commands)
{
	for (auto key : mKeyBinds) {
		if (sf::Keyboard::isKeyPressed(key.first) && 
			isRealTimeAction(key.second)
			) {
			commands.push(mActionBind[key.second]);
		}
	}
}

void Player::initializeKeyBinds()
{
	mKeyBinds[sf::Keyboard::A] = moveLeft;
	mKeyBinds[sf::Keyboard::D] = moveRight;
	mKeyBinds[sf::Keyboard::W] = moveUp;
	mKeyBinds[sf::Keyboard::S] = moveDown;
}

void Player::initializeActions()
{
	mActionBind[moveLeft].action = derivedAction<Airplane>(AircraftMover(-playerSpeed, 0.f));
	mActionBind[moveRight].action = derivedAction<Airplane>(AircraftMover(playerSpeed, 0.f));
	mActionBind[moveUp].action = derivedAction<Airplane>(AircraftMover(0.f, -playerSpeed));
	mActionBind[moveDown].action = derivedAction<Airplane>(AircraftMover(0.f,  playerSpeed));
}
