#include "Component.h"



GUI::Component::Component()
{
}


GUI::Component::~Component()
{
}

bool GUI::Component::isSelectable() const
{
	return false;
}


void GUI::Component::select()
{
}

void GUI::Component::deselect()
{
}

bool GUI::Component::isActive() const
{
	return false;
}

void GUI::Component::activate()
{
}

void GUI::Component::deactivate()
{
}
