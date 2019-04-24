#pragma once
#include <functional>
#include "SceneNode.h"
class SceneNode;
struct Command
{
	
	std::function<void(SceneNode&, sf::Time)>action;
	unsigned int category;
   
	
	

};

