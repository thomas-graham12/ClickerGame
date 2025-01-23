#include <iostream>
#include <SFML/Graphics.hpp>
#include "ClickObject.h"
#include "Cursor.h"
#include "Grandma.h"
#include "AppleTree.h"
#include "Lab.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Clicker Game", sf::Style::Titlebar | sf::Style::Close);

	ClickObject apple;

	/* Power Ups */
	Cursor cursor(apple);
	Grandma grandma(apple);
	AppleTree appleTree(apple);
	Lab lab(apple);
	/* Power Ups */

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

		window.clear(sf::Color(0, 100, 0, 255));

		/* Power Ups */
		lab.Update(window);
		appleTree.Update(window);
		grandma.Update(window);
		cursor.Update(window);
		apple.Update(window);
		/* Power Ups */

		window.display();
	}

	return 0;
}