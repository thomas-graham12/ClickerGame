#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ClickObject
{
public:
	ClickObject();
	void Click();
	void Hover(sf::RenderWindow& window);
	void DisplayCurrentApples();
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);

	// Getters
	float GetNumberOfApples() { return numberOfApples; }

	// Setters
	void RemoveNumberOfApples(float& removeAmountOfApples) { numberOfApples -= removeAmountOfApples; }

	void AddNumberOfApples(float& addAmountOfApples) { numberOfApples += addAmountOfApples; }

private:
	sf::Sprite clickingObj;
	sf::Texture clickingObjTexture;
	sf::Mouse mouse;

	bool bHoveringOverApple;
	bool bIsMouseHeld;
	
	sf::Font gameFont;
	sf::Text currentApples;

	

	float numberOfApples;
};