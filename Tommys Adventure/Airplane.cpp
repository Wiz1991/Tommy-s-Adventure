#include "Airplane.h"7



Airplane::Airplane()
{
}


Airplane::~Airplane()
{
}

void Airplane::drawCurrent(sf::RenderTarget & target, sf::RenderStates states)
{
	target.draw(mSprite, states);
}
