#include "SpriteNode.h"




SpriteNode::SpriteNode(sf::Texture& aTexture) : mSprite(aTexture)
{
}

SpriteNode::SpriteNode(sf::Texture & aTexture, sf::IntRect textureRect)
	: mSprite(aTexture, textureRect)
{
}

SpriteNode::~SpriteNode()
{
}

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(mSprite,states);
}
