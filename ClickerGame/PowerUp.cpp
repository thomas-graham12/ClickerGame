#include "PowerUp.h"

// TODO: Add functionality to all of the functions here

PowerUp::PowerUp(ClickObject& clickObjRef) : apple(clickObjRef)
{
	second = 1;
	applesGainedPerSecond = 0;
	powerUpCost = 0;

	applesGainedFromPowerUp = 0;

	bHoveringOverPowerUp = false;
	bIsMouseHeld = false;

	spriteBounds = powerUpSprite.getLocalBounds();

	if (!gameFont.loadFromFile("TerrariaFont.ttf"))
	{
		std::cout << "Cannot load font for power ups\n";
	}
	else
	{
		std::cout << "Loaded font for power ups\n";
	}

	if (!powerUpBuffer.loadFromFile("buyPowerUp.wav"))
	{
		std::cout << "Cannot load audio for power ups\n";
	}
	else
	{
		std::cout << "Loaded audio for power ups\n";
	}

	powerUpSound.setBuffer(powerUpBuffer);
	powerUpSound.setVolume(35);

	applesPerSecondText.setFillColor(sf::Color::Black);
	numberOfPowerUpText.setFillColor(sf::Color::Black);;
	priceText.setFillColor(sf::Color::Black);
}

void PowerUp::Buy()
{
	if (bHoveringOverPowerUp && mouse.isButtonPressed(sf::Mouse::Left))
	{
		if (!bIsMouseHeld)
		{
			if (apple.GetNumberOfApples() >= powerUpCost)
			{
				numberOfThisPowerUp += 1;
				apple.RemoveNumberOfApples(powerUpCost);
				std::cout << apple.GetNumberOfApples() << '\n';
				std::cout << "Bought item\n";
				bIsMouseHeld = true;
				powerUpCost = powerUpCost * 1.15;
				powerUpSound.play();
			}
			else
			{
				std::cout << "Too poor to buy this (x1).\n";
				bIsMouseHeld = true;
			}
		}
	}
	else if (bHoveringOverPowerUp && mouse.isButtonPressed(sf::Mouse::Right))
	{
		if (!bIsMouseHeld)
		{
			if (apple.GetNumberOfApples() >= (powerUpCost * 10))
			{
				numberOfThisPowerUp += 10;
				apple.RemoveNumberOfApples(powerUpCost);
				std::cout << apple.GetNumberOfApples() << '\n';
				std::cout << "Bought item\n";
				bIsMouseHeld = true;
				powerUpCost = powerUpCost * (1.15 * 10);
				powerUpSound.play();
			}
			else
			{
				std::cout << "Too poor to buy this (x10).\n";
				bIsMouseHeld = true;
			}
		}
	}
	else if (!bHoveringOverPowerUp && mouse.isButtonPressed(sf::Mouse::Left))
	{
		bIsMouseHeld = true;
	}
	else
	{
		bIsMouseHeld = false;
	}
}

void PowerUp::Click()
{
	applesGainedFromPowerUp = numberOfThisPowerUp * applesGainedPerSecond;
	if (timer.getElapsedTime().asSeconds() >= second)
	{
		apple.AddNumberOfApples(applesGainedFromPowerUp);
		totalApplesGainedOverTheGame += applesGainedFromPowerUp;
		timer.restart();
	}
}

void PowerUp::Hover(sf::RenderWindow& window)
{
	if (powerUpSprite.getGlobalBounds().contains(mouse.getPosition(window).x, mouse.getPosition(window).y))
	{
		bHoveringOverPowerUp = true;
		//std::cout << apple.GetNumberOfApples() << '\n';
	}
	else
	{
		bHoveringOverPowerUp = false;
	}
}

void PowerUp::DisplayPowerUpStats()
{
	std::ostringstream applesPerSecondStream;
	std::ostringstream powerUpCostStream;
	std::ostringstream numberOfPowerUpStream;
	applesPerSecondStream << std::setprecision(6) << applesGainedFromPowerUp;
	powerUpCostStream << std::setprecision(6) << powerUpCost;
	priceText.setString("Cost: " + powerUpCostStream.str());
	applesPerSecondText.setString("ApS: " + applesPerSecondStream.str());
	numberOfPowerUpText.setString("Owned: " + std::to_string(numberOfThisPowerUp));
}

void PowerUp::Draw(sf::RenderWindow& window)
{
	window.draw(applesPerSecondText);
	window.draw(numberOfPowerUpText);
	window.draw(priceText);
	window.draw(powerUpSprite);
}

void PowerUp::Update(sf::RenderWindow& window)
{
	//std::cout << totalApplesGainedOverTheGame << '\n';
	DisplayPowerUpStats();
	Click();
	Hover(window);
	Draw(window);
	Buy();
}
