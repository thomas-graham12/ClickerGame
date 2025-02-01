#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "ClickObject.h"

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

	ClickObject apple;
	//int firstUpgradeMilestone, secondUpgradeMilestone, thirdUpgradeMilestone, fourthUpgradeMilestone, fifthUpgradeMilestone;
	int upgradeMilestones[5];

	//sf::Texture firstUpgradeTexture, secondUpgradeTexture, thirdUpgradeTexture, fourthUpgradeTexture, fifthUpgradeTexture;
	sf::Texture upgradeTextures[5];

	//bool firstUpgradeDone, secondUpgradeDone, thirdUpgradeDone, fourthUpgradeDone, fifthUpgradeDone;
	bool bUpgradeCompletion[5];
};