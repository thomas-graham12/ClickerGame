#include "Lab.h"

Lab::Lab(ClickObject& clickObjRef) : PowerUp(clickObjRef)
{
	applesGainedPerSecond = 47.0f;
	powerUpCost = 10000.0f;

	if (!powerUpTexture.loadFromFile("labTexture.png"))
	{
		std::cout << "Cannot load lab texture\n";
	}
	else
	{
		std::cout << "Loaded\n";
	}
	

	powerUpSprite.setTexture(powerUpTexture);

	spriteBounds = powerUpSprite.getLocalBounds();

	powerUpSprite.setScale(sf::Vector2f(0.1f, 0.1f));
	powerUpSprite.setPosition(950, 580);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);

	priceText.setFont(gameFont);
	priceText.setCharacterSize(40);
	priceText.setPosition(1000, 540);

	applesPerSecondText.setFont(gameFont);
	applesPerSecondText.setCharacterSize(20);
	applesPerSecondText.setPosition(1000, 590);

	numberOfPowerUpText.setFont(gameFont);
	numberOfPowerUpText.setCharacterSize(15);
	numberOfPowerUpText.setPosition(1000, 620);
}