#include "ClickObject.h"
#include <iomanip>
#include <sstream>

ClickObject::ClickObject()
{
	if (!clickingObjTexture.loadFromFile("appleTexture.png"))
	{
		std::cout << "Texture not loaded\n";
	}
	else
	{
		std::cout << "Texture loaded\n";
	}
	clickingObjTexture.setSmooth(true);
	sf::FloatRect spriteBounds = clickingObj.getLocalBounds();

	clickingObj.setTexture(clickingObjTexture);
	clickingObj.setScale(sf::Vector2f(0.3f, 0.3f));
	clickingObj.setPosition(400, 240);
	clickingObj.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
	bHoveringOverApple = false;
	bIsMouseHeld = false;
	numberOfApples = 0.0f;

	if (!gameFont.loadFromFile("TerrariaFont.ttf"))
	{
		std::cout << "Font not loaded\n";
	}
	else
	{
		std::cout << "Font loaded\n";
	}




	currentApples.setFont(gameFont);
	currentApples.setCharacterSize(40);
	currentApples.setPosition(300, 100);
}

// TODO: Start on Click function
void ClickObject::Click()
{
	if (bHoveringOverApple && mouse.isButtonPressed(sf::Mouse::Left))
	{
		if (bIsMouseHeld == false)
		{
			bIsMouseHeld = true;
			std::cout << "Clicked\n";
			numberOfApples += 1;
			std::cout << "Apples: " << numberOfApples << '\n';
		}
	}
	else
	{
		bIsMouseHeld = false;
	}

}

void ClickObject::Hover(sf::RenderWindow& window)
{
	if (clickingObj.getGlobalBounds().contains(mouse.getPosition(window).x, mouse.getPosition(window).y))
	{
		bHoveringOverApple = true;
	}
	else
	{
		bHoveringOverApple = false;
	}
}

void ClickObject::DisplayCurrentApples()
{
	// Set decimal place
	std::ostringstream stream;
	stream << std::setprecision(4) << numberOfApples;
	currentApples.setString("Apples collected: " + stream.str());
}

void ClickObject::Draw(sf::RenderWindow& window)
{
	window.draw(currentApples);
	window.draw(clickingObj);
}

void ClickObject::Update(sf::RenderWindow& window)
{
	//std::cout << numberOfApples << '\n';
	DisplayCurrentApples();
	Click();
	Hover(window);
	Draw(window);
}
