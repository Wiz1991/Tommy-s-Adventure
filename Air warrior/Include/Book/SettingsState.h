#pragma once
#include <Book/State.hpp>
#include <Book/Container.hpp>
#include <Book/Button.hpp>
#include <Book/Label.hpp>
#include <array>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Book/Player.hpp>
#include <Book/Utility.hpp>
class SettingsState : public State
{
public:
	SettingsState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

	void updateLabels();
	void addButtonLabel(Player::Action action, float y, std::string text, Context context);
private:
	GUI::Container mGUIContainer;
	sf::Sprite mBackGroundSprite;
	std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabel;
};
