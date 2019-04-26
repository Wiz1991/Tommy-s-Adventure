#pragma once
#include "Entity.h"

#include "Category.h"

class Airplane : public Entity
{
public:
	enum class Type {
		Eagle,
	    Owl,
		Raptor
	};
	Airplane(sf::Texture& aTexture, sf::IntRect& textureRect,Type aType);
	Airplane(sf::Texture& aTexture,Type aType);
	
	Type getType() const;
	void setType(Type aType);
	virtual unsigned int getCategory();
	 

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const;
	
private:
	sf::Sprite mSprite;
	Type mType;
};

