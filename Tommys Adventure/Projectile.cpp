#include "Projectile.h"



Projectile::Projectile(sf::Texture& texture,sf::Vector2f position) :
	mSprite(texture),
    mPosition(position)
{
	mSprite.setPosition(mPosition);
}


Projectile::~Projectile()
{
}

void Projectile::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Projectile::updateCurrent(sf::Time dT)
{
	mSprite.move(0, -projectileSpeed);
}

void Projectile::fire()
{
	
}
