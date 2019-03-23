#include "Entity.h"



Entity::Entity(int HP) : mHealth(HP),
                         mVelocity()
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

int Entity::getHealth() const
{
	return mHealth;
}

bool Entity::isDestroyed() const
{
	return mHealth <= 0;
}

void Entity::updateCurrent(sf::Time dT)
{
	move(mVelocity * dT.asSeconds());
}





