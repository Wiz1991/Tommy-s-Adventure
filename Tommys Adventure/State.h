#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
class State
{
public:
	enum class Type
	{
		INTRO,
		MENU,
		PLAYING,
		GAME_OVER,
		TOTAL
	};

public:
	explicit State(State::Type aType)
		: mStateType(aType)
		, mNextState(mStateType)
	{}
	virtual ~State() {}

	State::Type GetNextState() const { return mNextState; }

	virtual void Update(sf::Time dT) = 0;
	virtual void processEvents(sf::Event event) = 0;
	virtual void draw() = 0;

protected:
	void PushState(State::Type aState) { mNextState = aState; }

private:
	const State::Type mStateType;
	State::Type mNextState;
};