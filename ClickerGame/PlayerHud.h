#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class PlayerHud
{
public:
	PlayerHud();
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);

private:
	sf::Texture playerhudBorderTexture;
	sf::Sprite playerHudBorderSprite;

	sf::Texture upgradeBracketTexture;
	sf::Sprite upgradeBracketSprite;
};