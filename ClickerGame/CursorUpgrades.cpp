#include "CursorUpgrades.h"

CursorUpgrades::CursorUpgrades(Cursor& existingCursor) : cursorRef(existingCursor)
{
	getTotalApplesGained = existingCursor.GetTotalApplesOverGame();

	upgradeMilestones[0] = 1;
	upgradeMilestones[1] = 3;
	upgradeMilestones[2] = 5;
	upgradeMilestones[3] = 7;
	upgradeMilestones[4] = 9;

	bUpgradeCompletion[0] = false;
	bUpgradeCompletion[1] = false;
	bUpgradeCompletion[2] = false;
	bUpgradeCompletion[3] = false;
	bUpgradeCompletion[4] = false;

	if (!upgradeTextures[0].loadFromFile("clickerFirstUpgrade.png") && !upgradeTextures[1].loadFromFile("clickerSecondUpgrade.png") && !upgradeTextures[2].loadFromFile("clickerThirdUpgrade.png")&& !upgradeTextures[3].loadFromFile("clickerFourthUpgrade.png")&& !upgradeTextures[4].loadFromFile("clickerFifthUpgrade.png"))
	{
		std::cout << "Couldn't load textures\n";
	}
}

void CursorUpgrades::Update(std::vector<sf::Sprite>& upgradeList)
{
	getTotalApplesGained = cursorRef.GetTotalApplesOverGame();  // Update with current value
	//std::cout << getTotalApplesGained << '\n';
	AddToVector(upgradeList);
}