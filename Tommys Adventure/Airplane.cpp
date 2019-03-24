#include "Airplane.h"






Airplane::Airplane(sf::Texture & aTexture, sf::IntRect & textureRect, Type aType)
	: mSprite(aTexture, textureRect),
	mType(aType)
	
{
	mSprite.setOrigin(aTexture.getSize().x / 2.f,aTexture.getSize().y/2.f);
}

Airplane::Airplane(sf::Texture & aTexture,Type aType)
	: mSprite(aTexture),
	  mType(aType)
{
	mSprite.setOrigin(aTexture.getSize().x / 2.f, aTexture.getSize().y / 2.f);
}

Airplane::Type Airplane::getType() const
{
	return mType;
}

void Airplane::setType(Type aType)
{
	mType = aType;
}
void Airplane::drawCurrent(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(mSprite, states);
}
