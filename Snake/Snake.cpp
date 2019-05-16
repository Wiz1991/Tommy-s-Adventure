#include "Snake.h"



Snake::Snake(int l_blockSize)
	: blockSize(l_blockSize)
{
	bodyRect.setSize(sf::Vector2f(blockSize - 1, blockSize - 1));
	Reset();

	
}

void Snake::setDirection(Direction l_dir)
{
	dir = l_dir;
}

Snake::Direction Snake::getDirection()
{
	return dir;
}

bool Snake::isAlive()
{
	return alive;
}

void Snake::toggleAlive()
{
	alive = !alive;
}

void Snake::setSpeed(int speed)
{
	mVelocity = speed;
}

int Snake::getVelocity()
{
	return mVelocity;
}

void Snake::Reset()
{
	mSnakeBody.clear();

	mSnakeBody.push_back(SnakeSegment(5, 6));
	mSnakeBody.push_back(SnakeSegment(5, 7));
	mSnakeBody.push_back(SnakeSegment(5, 8));

	setDirection(Direction::NONE);
	mLives = 3;
	mScore = 0;
	alive = true;
	mVelocity = 70;
}

void Snake::Cut()
{
}

void Snake::Update(sf::Time dT)
{
}

void Snake::Render(sf::RenderTarget& target)
{
}

sf::Vector2i Snake::getPosition()
{
	return (!mSnakeBody.empty() ? mSnakeBody.front().position : sf::Vector2i(1, 1));
}

int Snake::getLives()
{
	return mLives;
}

int Snake::getScore()
{
	return mScore;
}

void Snake::increaseScore()
{
	mScore += 10;
}

void Snake::move()
{
}

void Snake::lose()
{
	alive = false;
}

void Snake::checkCollision()
{
}




SnakeSegment::SnakeSegment(int x, int y)
	: position(x,y)
{

}
