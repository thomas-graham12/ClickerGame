#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

class ClickObject
{
public:
	ClickObject();
	void Click();
	void Hover(sf::RenderWindow& window);
	void DisplayCurrentApples();
	void Draw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window);

	// Dev functions
	void GiveApples();

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

	// dev vars
	bool bKeyIsPressed;
	
	sf::Font gameFont;
	sf::Text currentApples;

	float numberOfApples;

	sf::SoundBuffer appleClickBuffer;
	sf::Sound appleClickSound;
};