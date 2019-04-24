#pragma once
#include "Airplane.h"
#include "CommandQueue.h"
class Player
{
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
	void handleEvents(sf::Event& event, CommandQueue& commands);
	void handleRealTimeInput(const sf::Event& event, CommandQueue& commands);
	template<typename GameObject, typename Function>
	std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn) {
		return [=](SceneNode & node, sf::Time dT) {
			fn(static_cast<GameObject&>(node), dT)
		}
	}
	
};

