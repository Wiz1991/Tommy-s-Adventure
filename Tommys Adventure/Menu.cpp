#include "Menu.h"




void Menu::Update(sf::Time dT)
{
	print();
	PushState(State::Type::GAME_OVER);
}

void Menu::processEvents(sf::Event event)
{
}

void Menu::draw()
{
}

