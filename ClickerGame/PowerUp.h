#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ClickObject.h"
#include <sstream>
#include <iomanip>
#include <SFML/Audio.hpp>

class PowerUp
{
public:
	PowerUp(ClickObject& clickObjRef);
	void Buy();
	void Click();
	void Hover(sf::RenderWindow& window);
	void DisplayPowerUpStats();
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);

	// Getters
	float GetTotalApplesOverGame() const { return totalApplesGainedOverTheGame; }
	int GetNumberOfPowerUp() const { return numberOfThisPowerUp; }

protected:
	float applesGainedPerSecond;
	int second;
	float powerUpCost;

	float totalApplesGainedOverTheGame;

	int numberOfThisPowerUp;

	float applesGainedFromPowerUp;

	// This is for calculating whether upgrades should be shown or not
	

	bool bHoveringOverPowerUp;
	bool bIsMouseHeld;

	ClickObject& apple;
	sf::FloatRect spriteBounds;

	sf::Mouse mouse;

	sf::Clock timer;

	sf::Sprite powerUpSprite;
	sf::Texture powerUpTexture;

	sf::Font gameFont;

	sf::Text priceText;
	sf::Text applesPerSecondText;
	sf::Text numberOfPowerUpText;

	sf::SoundBuffer powerUpBuffer;
	sf::Sound powerUpSound;
};