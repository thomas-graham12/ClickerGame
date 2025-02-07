#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ClickObject.h"

// TODO: LET HTE PLAYER HOVER OVER UPGRADES AND SHOW WHAT THEY DO.

class Upgrades
{
public:
	Upgrades();
	void AddToVector(std::vector<sf::Sprite>& upgradeList);
	void Update(std::vector<sf::Sprite>& upgradeList);

	// Getters
	float GetTotalApplesFromThisPowerup() { return getTotalApplesGained; }

protected:
	float getTotalApplesGained;
	int getTotalNumberOfThisPowerup;
	float exponentialRate;

	ClickObject apple;
	//int firstUpgradeMilestone, secondUpgradeMilestone, thirdUpgradeMilestone, fourthUpgradeMilestone, fifthUpgradeMilestone;
	float upgradeMilestones[5];

	//sf::Texture firstUpgradeTexture, secondUpgradeTexture, thirdUpgradeTexture, fourthUpgradeTexture, fifthUpgradeTexture;
	sf::Texture upgradeTextures[5];

	//bool firstUpgradeDone, secondUpgradeDone, thirdUpgradeDone, fourthUpgradeDone, fifthUpgradeDone;
	bool bUpgradeCompletion[5];

	sf::Sprite spriteToAddToVector;
	sf::Sprite spriteToAddToVector2;
	sf::Sprite spriteToAddToVector3;
	sf::Sprite spriteToAddToVector4;
	sf::Sprite spriteToAddToVector5;
};