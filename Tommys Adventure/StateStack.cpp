#include "StateStack.h"



explicit StateStack::StateStack(State::Context context)
{
}

void StateStack::update(sf::Time dT)
{
	for (auto& itr : mStack) {
		if (!itr->update(dT))
			return;
	}

}

void StateStack::draw()
{
}

void StateStack::handleEvents(const sf::Event& event)
{
	for (auto& itr : mStack) {
		if (!itr->handleEvent())
			return;
	}
	applyPendingChanges();
}

void StateStack::pushState(States::ID id)
{
	
}

void StateStack::popState(States::ID id)
{

}

void StateStack::clearState()
{
	
}

bool StateStack::isEmpty() const
{
	return mStack.empty();
}

State::Ptr StateStack::createState(States::ID id)
{
	auto found = mFactories.find(id);
	return found->second();
}

void StateStack::applyPendingChanges()
{
	for (PendingChange change : mPendingChanges) {
		switch (change.action) {
		case Action::Pop:
			mStack.pop_back();
			break;
		case Action::Push:
			mStack.push_back(createState(change.id));
			break;
		case Action::Clear:
			mStack.clear();
			break;
		}
	}
	mPendingChanges.clear();
}
