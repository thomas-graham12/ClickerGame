#include "CursorUpgrades.h"

CursorUpgrades::CursorUpgrades(Cursor& existingCursor) : cursorRef(existingCursor)
{
	getTotalApplesGained = existingCursor.GetTotalApplesOverGame();

	upgradeMilestones[0] = 1;
	upgradeMilestones[1] = 1.2;
	upgradeMilestones[2] = 1.3;
	upgradeMilestones[3] = 1.4;
	upgradeMilestones[4] = 1.5;

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
	//std::cout << getTotalApplesGained << '\n';
	AddToVector(upgradeList);
}