#include "CursorUpgrades.h"

CursorUpgrades::CursorUpgrades(Cursor& existingCursor) : cursorRef(existingCursor)
{
	getTotalApplesGained = existingCursor.GetTotalApplesOverGame();
	getTotalNumberOfThisPowerup = existingCursor.GetNumberOfPowerUp();

	exponentialRate = 5.0f;

	//for (int i = 0; i < 5; i++)
	//{
	//	upgradeMilestones[i] = std::pow(exponentialRate, i);
	//}

	//  Testing values
	upgradeMilestones[0] = 0.1;
	upgradeMilestones[1] = 0.2;
	upgradeMilestones[2] = 0.3;
	upgradeMilestones[3] = 0.4;
	upgradeMilestones[4] = 0.5;

	bUpgradeCompletion[0] = false;
	bUpgradeCompletion[1] = false;
	bUpgradeCompletion[2] = false;
	bUpgradeCompletion[3] = false;
	bUpgradeCompletion[4] = false;

	if (!upgradeTextures[0].loadFromFile("clickerFirstUpgrade.png"))
	{
		std::cout << "Couldn't load 1st  upgrade textures\n";
	}
	if (!upgradeTextures[1].loadFromFile("clickerSecondUpgrade.png"))
	{
		std::cout << "Couldn't load 2nd upgrade textures\n";
	}
	if (!upgradeTextures[2].loadFromFile("clickerThirdUpgrade.png"))
	{
		std::cout << "Couldn't load 3rd upgrade textures\n";
	}
	if (!upgradeTextures[3].loadFromFile("clickerFourthUpgrade.png"))
	{
		std::cout << "Couldn't load 4th upgrade textures\n";
	}
	if (!upgradeTextures[4].loadFromFile("clickerFifthUpgrade.png"))
	{
		std::cout << "Couldn't load 5th upgades textures\n";
	}
}

void CursorUpgrades::Update(std::vector<sf::Sprite>& upgradeList)
{
	getTotalApplesGained = cursorRef.GetTotalApplesOverGame();  // Update with current value
	AddToVector(upgradeList);
}