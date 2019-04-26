#pragma once
#include <functional>
#include <SFML/System/Time.hpp>
#include "Category.h"
class SceneNode;
struct Command
{
	Command();
	std::function<void(SceneNode&, sf::Time)>action;
	unsigned int category;
};
template<typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn) {
	return [=](SceneNode & node, sf::Time dT) {
		fn(static_cast<GameObject&>(node), dT);
	};
}
