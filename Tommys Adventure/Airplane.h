#pragma once
#include "Entity.h"
class Airplane : public Entity
{
public:
	enum class Type {
		Eagle,
	    Owl
	};
	Airplane(sf::Texture& aTexture, sf::IntRect& textureRect,Type aType);
	Airplane(sf::Texture& aTexture,Type aType);
	
	Type getType() const;
	void setType(Type aType);
	 

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states);
	
private:
	sf::Sprite mSprite;
	Type mType;
};

