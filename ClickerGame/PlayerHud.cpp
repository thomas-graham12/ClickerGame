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

	startPosX = 195;
	offsetX = 95.7;

	upgradeRows = 2;
	upgradeColumns = 8;

	// TODO: Make it so everything spawns correctly
	for (int i = 1; i < upgradeRows; i++)
	{
		for (int k = 0; k < sizeof(upgradeSprites) / sizeof(upgradeSprites[0]); k++)
		{
			upgradeSprites[k].setTexture(upgradeBracketTexture);
			upgradeSprites[k].setScale(0.35f, 0.35f);
			if (i == 1)
			{
				upgradeSprites[k].setPosition(startPosX + (k * offsetX), 560);
				std::cout << "Set position X\n";
			}
			else if (i == 2)
			{
				upgradeSprites[k].setPosition(startPosX + (k * offsetX), 600);
				std::cout << "Set position X and m ade a new row\n";
			}
		}
	}
}

void PlayerHud::Draw(sf::RenderWindow& window)
{
	
	for (int i = 0; i < sizeof(upgradeSprites) / sizeof(upgradeSprites[0]); i++)
	{
		window.draw(upgradeSprites[i]);
	}
	//window.draw(upgradeBracketSprite);
	window.draw(playerHudBorderSprite);
}

void PlayerHud::Update(sf::RenderWindow& window)
{
	Draw(window);
}
