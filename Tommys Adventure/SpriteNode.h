#pragma once
#include "SceneNode.h"
class SpriteNode : public SceneNode
{
public:
	SpriteNode(sf::Texture& aTexture);
	SpriteNode(sf::Texture& aTexture, sf::IntRect& textureRect);
	~SpriteNode();
	void drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const;
	
		sf::Sprite mSprite;

};

