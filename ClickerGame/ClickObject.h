#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ClickObject
{
public:
	ClickObject();
	void Click();
	void Hover(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);

	// Getters
	float GetNumberOfApples() { return numberOfApples; }

	// Setters
	void SetNumberOfApples(float& removeAmountOfApples) { numberOfApples -= removeAmountOfApples; }

private:
	sf::Sprite clickingObj;
	sf::Texture clickingObjTexture;
	sf::Mouse mouse;

	bool bHoveringOverApple;
	bool bIsMouseHeld;

	float numberOfApples;
};