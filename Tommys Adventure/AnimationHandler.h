#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"
#include <vector>

namespace Animation {
	enum Direction {
		None,
        Up,
		Right,
		Down,
		Left
	};
}

class AnimationHandler : public sf::Drawable, public sf::Transformable
{
public:
	AnimationHandler();
	AnimationHandler(sf::Texture& aTexture);

	void setTexture(sf::Texture& aTexture);
	void setDuration(sf::Time time);
	void toggleRepeat();
	void setFrameSize(sf::Vector2i aSize);
	void setFrameSize(float sizeX, float sizeY);
	void update(sf::Time dT);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
private:
	sf::IntRect mFrames;
	sf::Vector2i mFrameSize;
	sf::Time mDuration;
	sf::Time mElapsedTime;
	Animation::Direction mDirection;
	sf::Sprite mSprite;
	bool mRepeat;



};

 