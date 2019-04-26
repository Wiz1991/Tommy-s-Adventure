#pragma once
#include "Command.h"
#include <SFML/Window/Event.hpp>
#include "Airplane.h"
#include "CommandQueue.h"
#include <map>
#include <SFML/Window/Keyboard.hpp>
class Player
{
	enum Action {
		moveLeft,
		moveRight,
		moveUp,
		moveDown
	};
public:
	Player();
	struct AircraftMover {
		AircraftMover(float vX, float vY) : mVelocity(vX, vY)
		{
		}
		void operator() (Airplane& plane, sf::Time dT) const {
			plane.accelerate(mVelocity);
		}
		sf::Vector2f mVelocity;
	};
public:
	void assignKeybind(sf::Keyboard::Key key, Action action);
	bool isRealTimeAction(Action action);
public:
	void handleEvents(sf::Event& event, CommandQueue& commands);
	void handleRealTimeInput(CommandQueue& commands);
private:
	std::map<sf::Keyboard::Key, Action> mKeyBinds;
	std::map<Action, Command> mActionBind;
	
};

