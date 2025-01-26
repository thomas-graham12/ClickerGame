#include "PlayerHud.h"

PlayerHud::PlayerHud()
{
	if (!playerhudBorderTexture.loadFromFile("AppleClicker Outline.png"))
	{
		std::cout << "Could not load player hud border\n";
	}
	else
	{
		std::cout << "Loaded player hud border\n";
	}

	playerHudBorderSprite.setTexture(playerhudBorderTexture);

	if (!upgradeBracketTexture.loadFromFile("upgradeBracket.png"))
	{
		std::cout << "Could not load upgrade bracket texture\n";
	}
	else
	{
		std::cout << "Loaded upgrade bracket texture\n";
	}

	upgradeBracketSprite.setTexture(upgradeBracketTexture);
	// TODO: This is a good size. need to span it across the bottom where the upgrades will be
	upgradeBracketSprite.setScale(0.4f, 0.4f);

	upgradeRows = 2;
	upgradeColumns = 6;

	for (int i = 0; i < 1; i++)
	{
		for (int k = 0; k < upgradeColumns; k++)
		{
			if (i == 0)
			{

			}
		}
	}
}

void PlayerHud::Draw(sf::RenderWindow& window)
{
	window.draw(upgradeBracketSprite);
	window.draw(playerHudBorderSprite);
}

void PlayerHud::Update(sf::RenderWindow& window)
{
	Draw(window);
}
