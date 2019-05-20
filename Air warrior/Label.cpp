#include "Label.h"



namespace GUI
{
	Label::Label(std::string text, const FontHolder& fonts)
		: mText(text, fonts.get(Fonts::Main), 16)
	{
	}

	bool Label::isSelectable() const
	{
		return false;
	}

	void Label::setText(std::string text)
	{
		mText.setString(text);
	}

	void Label::handleEvent(const sf::Event& event)
	{
		//do nothing
	}
	
	void Label::draw(sf::RenderTarget& target, sf::RenderStates states)
	{
		states.transform *= getTransform();
		target.draw(mText, states);
	}
}


