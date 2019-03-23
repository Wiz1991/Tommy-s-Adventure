#pragma once
#include "SceneNode.h"
class Entity : public SceneNode
{
public:
	Entity(int HP);
	Entity() {}

	void setVelocity(sf::Vector2f aVelocity);
	void setVelocity(float vX, float vY);
	sf::Vector2f getVelocity() const;
	int getHealth()const;
	bool isDestroyed() const;
private:
	virtual void updateCurrent(sf::Time dT);


private:
	sf::Vector2f mVelocity;
	int mHealth;
};

