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
	bKeyIsPressed = false;
	numberOfApples = 0.0f;

	if (!gameFont.loadFromFile("TerrariaFont.ttf"))
	{
		std::cout << "Font not loaded\n";
	}
	else
	{
		std::cout << "Font loaded\n";
	}

	if (!appleClickBuffer.loadFromFile("appleSound.mp3"))
	{
		std::cout << "Cannot load apple click sound\n";
	}
	else
	{
		std::cout << "Apple click sound loaded\n";
	}

	appleClickSound.setBuffer(appleClickBuffer);
	appleClickSound.setVolume(35);

	currentApples.setFont(gameFont);
	currentApples.setCharacterSize(40);
	currentApples.setPosition(300, 100);
	currentApples.setFillColor(sf::Color::Black);
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
			appleClickSound.play();
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
	stream << std::setprecision(6) << numberOfApples;
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
	GiveApples();
	DisplayCurrentApples();
	Click();
	Hover(window);
	Draw(window);
}

void ClickObject::GiveApples()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (bKeyIsPressed == false)
		{
			bKeyIsPressed = true;
			std::cout << "Clicked\n";
			numberOfApples += 1000;
			//std::cout << "Apples: " << numberOfApples << '\n';
		}
	}
	else
	{
		bKeyIsPressed = false;
	}
}
