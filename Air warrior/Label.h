#pragma once
#include "Component.h"
#include <SFML/Graphics/Text.hpp>
#include "Book/ResourceHolder.hpp"
#include "Book/ResourceIdentifiers.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <string.h>
#include <string>

namespace GUI
{
	class Label : public Component
	{
	public:
		Label(std::string text, const FontHolder& fonts);
		virtual bool isSelectable() const;
		void setText(std::string text);

		void handleEvent(const sf::Event& event);

	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states);
	private:
		sf::Text mText;
	};
}
