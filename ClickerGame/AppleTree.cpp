#include "AppleTree.h"

AppleTree::AppleTree(ClickObject& clickObjRef) : PowerUp(clickObjRef)
{
	applesGainedPerSecond = 8.0f;
	powerUpCost = 1100.0f;

	if (!powerUpTexture.loadFromFile("treeTexture.png"))
	{
		std::cout << "Cannot load apple tree texture\n";
	}
	else
	{
		std::cout << "Loaded\n";
	}


	powerUpSprite.setTexture(powerUpTexture);

	spriteBounds = powerUpSprite.getLocalBounds();

	powerUpSprite.setScale(sf::Vector2f(0.0085f, 0.01f));
	powerUpSprite.setPosition(995, 322);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);

	priceText.setFont(gameFont);
	priceText.setCharacterSize(40);
	priceText.setPosition(1025, 275);

	applesPerSecondText.setFont(gameFont);
	applesPerSecondText.setCharacterSize(20);
	applesPerSecondText.setPosition(1025, 315);

	numberOfPowerUpText.setFont(gameFont);
	numberOfPowerUpText.setCharacterSize(15);
	numberOfPowerUpText.setPosition(1025, 335);
}
