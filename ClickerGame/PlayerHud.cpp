#include "PlayerHud.h"

PlayerHud::PlayerHud(Cursor& cursor, AppleTree& appleTree, Grandma& grandma, Lab& lab)
	: cursorUpgrades(cursor), grandmaUpgrades(grandma)
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

	upgradeCount = 0;

	bShowUpgradesOnNewLine = false;
}

void PlayerHud::Draw(sf::RenderWindow& window)
{
	int index = 0;
	for (auto& sprite : upgradeList)
	{
		sprite.setScale(0.5f, 0.5f);
		sprite.setPosition(190.0f + index * 162, 580.0f);

		window.draw(sprite);
		index++;
	}

	window.draw(playerHudBorderSprite);
}

void PlayerHud::Update(sf::RenderWindow& window)
{
	cursorUpgrades.Update(upgradeList);
	grandmaUpgrades.Update(upgradeList);
	appleTreeUpgrades.Update(upgradeList);
	labUpgrades.Update(upgradeList);
	Draw(window);
}
