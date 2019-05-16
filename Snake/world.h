#pragma once
#include "Snake.h"
class World
{
public:
	World();
	void update(sf::Time dt);
	void Draw();
	

private:
	Snake* mSnake;
};

