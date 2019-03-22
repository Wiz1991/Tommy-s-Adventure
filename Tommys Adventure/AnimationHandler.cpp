#include "AnimationHandler.h"



AnimationHandler::AnimationHandler()
    : mDuration(sf::Time::Zero),
	mDirection(Animation::Direction::None),
	mFrameSize(),
	mRepeat(false),
	mElapsedTime(sf::Time::Zero)
{

}

AnimationHandler::AnimationHandler(sf::Texture& aTexture)
	: mSprite(aTexture),
	mDuration(sf::Time::Zero),
	mDirection(Animation::Direction::None),
	mFrameSize(),
	mRepeat(false),
	mElapsedTime(sf::Time::Zero)
{
}

void AnimationHandler::setTexture(sf::Texture & aTexture)
{
	mSprite.setTexture(aTexture);
}

void AnimationHandler::setDuration(sf::Time time)
{
	mDuration= time;
}

void AnimationHandler::toggleRepeat()
{
	mRepeat = !mRepeat;
}

void AnimationHandler::setFrameSize(sf::Vector2i aSize)
{
	mFrameSize.x = aSize.x;
	mFrameSize.y = aSize.y;
}

void AnimationHandler::setFrameSize(float sizeX, float sizeY)
{
	mFrameSize.x = sizeX;
	mFrameSize.y = sizeY;
}

void AnimationHandler::update(sf::Time dT)
{

}

void AnimationHandler::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
}




