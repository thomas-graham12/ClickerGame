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
}

void PlayerHud::ShowUpgrades()
{

	cursorUpgrades.GetTotalApplesFromThisPowerup();

	for (auto sprite : upgradeList)
	{
		int i = 0;
		sprite.setScale(0.35f, 0.35f);
		sprite.setPosition(150.0f + i * 50.0f, 300.0f);
		i++;
	}
}

void PlayerHud::Draw(sf::RenderWindow& window)
{
	for (auto sprite : upgradeList)
	{
		window.draw(sprite);
	}
	window.draw(playerHudBorderSprite);
}

void PlayerHud::Update(sf::RenderWindow& window)
{
	cursorUpgrades.Update(upgradeList);
	cursorUpgrades.UpdateApples();
	ShowUpgrades();
	Draw(window);
}
