#pragma once
#include "Entity.h"
class Airplane : public Entity 
{
 public:
	Airplane();
	~Airplane();

private:
	void drawCurrent(sf::RenderTarget& target, sf::RenderStates states);
private:
	sf::Sprite mSprite;
};

