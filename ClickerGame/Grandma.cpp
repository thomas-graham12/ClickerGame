#include "Grandma.h"

Grandma::Grandma(ClickObject& clickObjref) : PowerUp(clickObjref)
{
	applesGainedPerSecond = 5.0f;
	powerUpCost = 20.0f;

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
	powerUpSprite.setPosition(1100, 250);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
}
