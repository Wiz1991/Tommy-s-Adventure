#pragma once
#include "SceneNode.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
class Entity : public SceneNode
{
public:
	Entity();


	void setVelocity(sf::Vector2f aVelocity);
	void setVelocity(float vX, float vY);
	sf::Vector2f getVelocity() const;
	void accelerate(sf::Vector2f velocity);
	void accelerate(float vX, float vY);
private:
	virtual void updateCurrent(sf::Time dT);


private:
	sf::Vector2f mVelocity;
};

