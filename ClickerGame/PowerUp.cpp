#include "PowerUp.h"

// TODO: Add functionality to all of the functions here

PowerUp::PowerUp(ClickObject& clickObjRef) : apple(clickObjRef)
{
	second = 1;
	applesGainedPerSecond = 0;
	powerUpCost = 0;

	bHoveringOverPowerUp = false;
	bIsMouseHeld = false;

	spriteBounds = powerUpSprite.getLocalBounds();
}

void PowerUp::Buy()
{
	if (bHoveringOverPowerUp && mouse.isButtonPressed(sf::Mouse::Left))
	{
		if (bIsMouseHeld == false)
		{
			if (apple.GetNumberOfApples() >= powerUpCost)
			{
				numberOfThisPowerUp += 1;
				apple.SetNumberOfApples(powerUpCost);
				std::cout << apple.GetNumberOfApples() << '\n';
				std::cout << "Bought item\n";
				bIsMouseHeld = true;
			}
			else
			{
				std::cout << "Too poor to buy this.\n";
				bIsMouseHeld = true;
			}

		}

	}
	else
	{
		bIsMouseHeld = false;
	}
}

void PowerUp::Click()
{
}

void PowerUp::Hover(sf::RenderWindow& window)
{
	if (powerUpSprite.getGlobalBounds().contains(mouse.getPosition(window).x, mouse.getPosition(window).y))
	{
		bHoveringOverPowerUp = true;
		std::cout << apple.GetNumberOfApples() << '\n';
	}
	else
	{
		bHoveringOverPowerUp = false;
	}
}

void PowerUp::Draw(sf::RenderWindow& window)
{
	window.draw(powerUpSprite);
}

void PowerUp::Update(sf::RenderWindow& window)
{
	Hover(window);
	Draw(window);
	Buy();
}
