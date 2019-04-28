#pragma once
#include "State.h"
#include "StateIdentifiers.h"
class StateStack
{
public:
	enum Action {
		Push,
		Pop,
		Clear
	};
	explicit StateStack(State::Context context);
	template<typename T>
	void registerStates(States::ID id);

	void update(sf::Time dT);
	void draw();
	void handleEvents(const sf::Event& event);

	void pushState(States::ID id);
	void popState(States::ID id);
	void clearState();

	bool isEmpty() const;
private:
	State::Ptr createState(States::ID id);
	void applyPendingChanges();

	struct PendingChange {
		StateStack::Action action;
		States::ID id;
	};
private:
	std::vector<State::Ptr> mStack;
	std::vector<PendingChange> mPendingChanges;
	State::Context mContext;
	std::map<States::ID, std::function<State::Ptr()>> mFactories;
	
};

template<typename T>
inline void StateStack::registerStates(States::ID id)
{
	mFactories[id] = [this]() {
		return State::Ptr(new T(*this, mContext));
	};
}
