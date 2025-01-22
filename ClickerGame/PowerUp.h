#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class PowerUp
{
public:
	PowerUp();
	void Buy();
	void Click();
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);
protected:
	float applesGainedPerSecond;
	int second;
	float powerUpCost;
};