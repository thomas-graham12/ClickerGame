#include "PlayerHud.h"

PlayerHud::PlayerHud(Cursor& cursor, AppleTree& appleTree, Grandma& grandma, Lab& lab)
	: cursorUpgrades(cursor)
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
}

// TODO: Make it so they are drawn at specific areas
void PlayerHud::Draw(sf::RenderWindow& window)
{
	for (auto& sprite : upgradeList)
	{
		//std::cout << "drawing\n";
		window.draw(sprite);
	}
	window.draw(playerHudBorderSprite);
}

void PlayerHud::Update(sf::RenderWindow& window)
{
	//std::cout << upgradeCount << '\n';
	cursorUpgrades.Update(upgradeList);
	Draw(window);
}
