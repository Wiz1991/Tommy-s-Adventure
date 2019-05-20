#pragma once
#include <Book/SceneNode.hpp>
#include <Book/ResourceIdentifiers.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>
#include <SFML/Graphics/Text.hpp>

class TextNode : public SceneNode
{
public:
	explicit TextNode(const FontHolder& fonts, const std::string& text);

	void setText(std::string& text);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
private:
	sf::Text mText;
};
