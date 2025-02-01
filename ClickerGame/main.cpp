#include <iostream>
#include <SFML/Graphics.hpp>
#include "ClickObject.h"
#include "Cursor.h"
#include "Grandma.h"
#include "AppleTree.h"
#include "Lab.h"
#include "PlayerHud.h"
#include "CursorUpgrades.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Clicker Game", sf::Style::Titlebar | sf::Style::Close);

	window.setFramerateLimit(60);

	ClickObject apple;
	PlayerHud playerHud;

	/* Power Ups */
	Cursor cursor(apple);
	Grandma grandma(apple);
	AppleTree appleTree(apple);
	Lab lab(apple);
	/* Power Ups */

	/* Upgrades */
	CursorUpgrades cursorUpgrades;
	/* Upgrades */


	//sf::Clock clock;
	//float lastTime = 0;

	// BACKGROUND

	// Link for more background images: https://lexica.art/prompt/ca25aea3-970f-47d6-9444-a649d775d3ae

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	if (!backgroundTexture.loadFromFile("background.png"))
	{
		std::cout << "Can't load background image\n";
	}
	else
	{
		std::cout << "Loaded background image\n";
	}

	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.scale(0.7, 0.7);
	backgroundSprite.setPosition(-370, 0);

	// BACKGROUND

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

		//float currentTime = clock.restart().asSeconds();
		//float fps = 1.f / currentTime;
		//lastTime = currentTime;
		//std::cout << fps << '\n';

		window.clear(sf::Color(0, 100, 0, 255));

		window.draw(backgroundSprite);
		playerHud.Update(window);

		/* Power Ups */
		lab.Update(window);
		appleTree.Update(window);
		grandma.Update(window);
		cursor.Update(window);
		apple.Update(window);
		/* Power Ups */

		/* Upgrades */
		/* Upgrades */

		window.display();
	}

	return 0;
}