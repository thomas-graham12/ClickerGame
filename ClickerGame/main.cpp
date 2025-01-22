#include <iostream>
#include <SFML/Graphics.hpp>
#include "ClickObject.h"
#include "Cursor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Clicker Game", sf::Style::Titlebar | sf::Style::Close);

	ClickObject apple;
	Cursor cursor;

	cursor.PrintSecond();
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		window.clear(sf::Color::Blue);

		apple.Update(window);

		window.display();
	}

	return 0;
}