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

	powerUpSprite.setScale(sf::Vector2f(0.075f, 0.075f));
	powerUpSprite.setPosition(995, 413);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);

	priceText.setFont(gameFont);
	priceText.setCharacterSize(40);
	priceText.setPosition(1025, 367);

	applesPerSecondText.setFont(gameFont);
	applesPerSecondText.setCharacterSize(20);
	applesPerSecondText.setPosition(1025, 407);

	numberOfPowerUpText.setFont(gameFont);
	numberOfPowerUpText.setCharacterSize(15);
	numberOfPowerUpText.setPosition(1025, 427);
}