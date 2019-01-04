#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tommy's Adventure");
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(200.f, 200.f));
	rectangle.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			window.draw(rectangle);
			window.display();


		}

	}
}