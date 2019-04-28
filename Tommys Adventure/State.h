#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include "ResourceManager.h"

#include <vector>
#include <map>
#include <functional>
#include "StateIdentifiers.h"
#include "Player.h"

class StateStack;


class State
{
public:
	typedef std::unique_ptr<State> Ptr;
    struct Context{
		Context(sf::RenderWindow& window,
			TextureHolder& mTextureHolder,
			Player& player,
			FontHolder& fonts) :

			mPlayer(player),
			textures(mTextureHolder),
			mWindow(window),
			FontHolder(fonts)
		{}

		sf::RenderWindow& mWindow;
		TextureHolder& textures;
		FontHolder& FontHolder;
		Player& mPlayer;

	};

	State(StateStack& stack,Context context);
	
	virtual void draw() = 0;
	virtual bool update(sf::Time dT) = 0;
	virtual bool handleEvent(const sf::Event & event) = 0;

private:
	void requestStackPush(States::ID id);
	void requestStackPop();
	void requestStackClear();
	
	Context getContext() const;
private:
	StateStack* mStack;
	Context mContext;

};
