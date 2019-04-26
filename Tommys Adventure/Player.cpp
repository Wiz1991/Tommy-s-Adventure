#include "Player.h"

Player::Player()
{
	mKeyBinds[sf::Keyboard::Left] = moveLeft;
	mActionBind[moveLeft].action = [](SceneNode & node, sf::Time dT) {
		node.move(-30 * dT.asSeconds(), 0);
	};

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
