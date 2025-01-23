#include "Cursor.h"

Cursor::Cursor(ClickObject& clickObjRef) : PowerUp(clickObjRef)
{
	applesGainedPerSecond = 1.0f;
	powerUpCost = 10.0f;

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
	powerUpSprite.setPosition(1100, 100);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
}