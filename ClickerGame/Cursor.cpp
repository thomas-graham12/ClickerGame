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

	powerUpSprite.setScale(sf::Vector2f(0.03f, 0.03f));
	powerUpSprite.setPosition(995, 140);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);

	priceText.setFont(gameFont);
	priceText.setCharacterSize(40);
	priceText.setPosition(1025, 95);

	applesPerSecondText.setFont(gameFont);
	applesPerSecondText.setCharacterSize(20);
	applesPerSecondText.setPosition(1025, 135);

	numberOfPowerUpText.setFont(gameFont);
	numberOfPowerUpText.setCharacterSize(15);
	numberOfPowerUpText.setPosition(1025, 155);
}