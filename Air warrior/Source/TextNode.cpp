#include "..\Include\Book\TextNode.h"

TextNode::TextNode(const FontHolder& fonts, const std::string& text)
{
}

void TextNode::setText(std::string& text)
{
	mText.setString(text);
}

void TextNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(mText, states);
}