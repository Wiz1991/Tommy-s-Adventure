#include "Entity.h"

Entity::Entity()
	: mVelocity(0, 0)
{
}

void Entity::setVelocity(sf::Vector2f aVelocity)
{
	mVelocity = aVelocity;
}

void Entity::setVelocity(float vX, float vY)
{
	mVelocity.x = vX;
	mVelocity.y = vY;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}


void Entity::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Entity::accelerate(float vX, float vY)
{
	mVelocity.x += vX;
	mVelocity.y += vY;
}

void Entity::updateCurrent(sf::Time dT)
{
	move(mVelocity * dT.asSeconds());
}