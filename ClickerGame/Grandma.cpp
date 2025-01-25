#include "Grandma.h"

Grandma::Grandma(ClickObject& clickObjref) : PowerUp(clickObjref)
{
	applesGainedPerSecond = 1.0f;
	powerUpCost = 100.0f;

	if (!powerUpTexture.loadFromFile("grandmaTexture.png"))
	{
		std::cout << "Cannot load grandma texture\n";
	}
	else
	{
		std::cout << "Loaded\n";
	}


	powerUpSprite.setTexture(powerUpTexture);

	spriteBounds = powerUpSprite.getLocalBounds();

	powerUpSprite.setScale(sf::Vector2f(0.1f, 0.1f));
	powerUpSprite.setPosition(950, 250);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);

	priceText.setFont(gameFont);
	priceText.setCharacterSize(40);
	priceText.setPosition(1000, 210);

	applesPerSecondText.setFont(gameFont);
	applesPerSecondText.setCharacterSize(20);
	applesPerSecondText.setPosition(1000, 260);
}
