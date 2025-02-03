#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "CursorUpgrades.h"

#include "Cursor.h"
#include "AppleTree.h"
#include "Grandma.h"
#include "Lab.h"

class PlayerHud
{
public:
	PlayerHud(Cursor& cursor, AppleTree& appleTree, Grandma& grandma, Lab& lab);
	void ShowUpgrades();
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);

private:
	sf::Texture playerhudBorderTexture;
	sf::Sprite playerHudBorderSprite;

	sf::Texture upgradeBracketTexture;
	sf::Sprite upgradeBracketSprite;

	float startPosX;
	float offsetX;

	int upgradeCount;

	CursorUpgrades cursorUpgrades;

	std::vector<sf::Sprite> upgradeList;
};