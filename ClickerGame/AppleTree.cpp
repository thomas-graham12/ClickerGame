#include "AppleTree.h"

AppleTree::AppleTree(ClickObject& clickObjRef) : PowerUp(clickObjRef)
{
	applesGainedPerSecond = 10.0f;
	powerUpCost = 100.0f;

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

	powerUpSprite.setScale(sf::Vector2f(0.015f, 0.015f));
	powerUpSprite.setPosition(1100, 420);
	powerUpSprite.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
}
