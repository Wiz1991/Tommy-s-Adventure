#pragma once
#include "Entity.h"
  class Projectile : public Entity
{
public:
	Projectile(sf::Texture& texture,sf::Vector2f position);
	
	~Projectile();
private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual void updateCurrent(sf::Time dT);
	void fire();

private:
	sf::Sprite mSprite;
	const float projectileSpeed = 300.f;
	sf::Vector2f mPosition;
	std::vector <Projectile> mProjectiles;
};

