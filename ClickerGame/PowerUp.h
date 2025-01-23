#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ClickObject.h"

class PowerUp
{
public:
	PowerUp(ClickObject& clickObjRef);
	void Buy();
	void Click();
	void Hover(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
protected:
	float applesGainedPerSecond;
	int second;
	float powerUpCost;

	int numberOfApples;

	int numberOfThisPowerUp;

	bool bHoveringOverPowerUp;
	bool bIsMouseHeld;

	ClickObject& apple;
	sf::FloatRect spriteBounds;

	sf::Mouse mouse;

	sf::Sprite powerUpSprite;
	sf::Texture powerUpTexture;
};