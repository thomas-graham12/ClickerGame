#include "Cursor.h"

Cursor::Cursor(ClickObject& clickObjRef) : PowerUp(clickObjRef)
{
	applesGainedPerSecond = 0.1f;
	powerUpCost = 15.0f;

	if (!powerUpTexture.loadFromFile("cursorTexture.png"))
	{
		std::cout << "Cannot load cursor texture\n";
	}
	else
	{
		std::cout << "Loaded\n";
	}


	powerUpSprite.setTexture(powerUpTexture);

	spriteBounds = powerUpSprite.getLocalBounds();

	powerUpSprite.setScale(sf::Vector2f(0.05f, 0.05f));
	powerUpSprite.setPosition(950, 100);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);

	priceText.setFont(gameFont);
	priceText.setCharacterSize(40);
	priceText.setPosition(1000, 60);

	applesPerSecondText.setFont(gameFont);
	applesPerSecondText.setCharacterSize(20);
	applesPerSecondText.setPosition(1000, 110);

	numberOfPowerUpText.setFont(gameFont);
	numberOfPowerUpText.setCharacterSize(15);
	numberOfPowerUpText.setPosition(1000, 140);
}