#ifndef BOOK_UTILITY_HPP
#define BOOK_UTILITY_HPP
#include <SFML/Window/Keyboard.hpp>
#include <sstream>

namespace sf
{
	class Sprite;
	class Text;
}

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value);
std::string keyToString(sf::Keyboard::Key key);
void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include <Book/Utility.inl>
#endif // BOOK_UTILITY_HPP