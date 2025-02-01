#include "CursorUpgrades.h"

CursorUpgrades::CursorUpgrades()
{
	Cursor cursUpgrade(apple);
	getTotalApplesGained = cursUpgrade.GetTotalApplesOverGame();

	upgradeMilestones[0] = 5;
	upgradeMilestones[1] = 10;
	upgradeMilestones[2] = 15;
	upgradeMilestones[3] = 20;
	upgradeMilestones[4] = 25;

	if (!upgradeTextures[0].loadFromFile("clickerFirstUpgrade.png") && !upgradeTextures[1].loadFromFile("clickerSecondUpgrade.png") && !upgradeTextures[2].loadFromFile("clickerThirdUpgrade.png")&& !upgradeTextures[3].loadFromFile("clickerFourthUpgrade.png")&& !upgradeTextures[4].loadFromFile("clickerFifthUpgrade.png"))
	{
		std::cout << "Couldn't load textures\n";
	}
}

void CursorUpgrades::UpdateApples()
{
	
}
