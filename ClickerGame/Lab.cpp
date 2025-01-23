#include "Lab.h"

Lab::Lab(ClickObject& clickObjRef) : PowerUp(clickObjRef)
{
	applesGainedPerSecond = 20.0f;
	powerUpCost = 150.0f;

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
	powerUpSprite.setPosition(1100, 580);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
}
