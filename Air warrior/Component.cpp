#include "Component.h"
namespace GUI
{
	Component::Component() :
		mIsSelected(false),
		mIsActive(false)
	{
	}

	bool Component::isSelectable() const
	{
		return false;
	}

	void Component::select()
	{
	}

	void Component::deselect()
	{
	}

	bool Component::isActive() const
	{
		return false;
	}

	void Component::activate()
	{
	}

	void Component::deactivate()
	{
	}
}