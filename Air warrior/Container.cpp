#include "Container.h"

namespace GUI {
	Container::Container()
		: mChildren()
		, mSelectedChild(-1)
	{
	}
	void Container::push(Component::Ptr component)
	{
		mChildren.push_back(component);
		if (!hasSelection() && component->isSelectable()) {
			select(mChildren.size() - 1);
		}
	}

	bool Container::isSelectable() const
	{
		return false;
	}

	void Container::handelEvent(const sf::Event & event)
	{
		if (hasSelection() && mChildren[mSelectedChild]->isActive())
			mChildren[mSelectedChild]->handleEvent(event);
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
				selectPrevious();
			if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				selectNext();
			if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
			{
				if (hasSelection())
					mChildren[mSelectedChild]->activate();
			}
		}
	}

	void Container::select(std::size_t index)
	{
		if (mChildren[index]->isSelectable()) {
			if (hasSelection())
				mChildren[mSelectedChild]->deselect();
			mSelectedChild = index;
			mChildren[mSelectedChild]->select();
		}
	}

	void Container::selectNext()
	{
		if (!hasSelection()) return;
		int index = mSelectedChild;
		do {
			index = (index + 1);
		} while (!mChildren[index]->isSelectable());
		select(index);
	}

	void Container::selectPrevious()
	{
		if (!hasSelection()) return;
		int index = mSelectedChild;
		do {
			index = --index;
		} while (!mChildren[index]->isSelectable());
		select(index);
	}

	bool Container::hasSelection()
	{
		return mSelectedChild >= 0;
	}
	void Container::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		for (const Component::Ptr& child : mChildren)
			target.draw(*child, states);
	}
}