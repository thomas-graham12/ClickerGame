#include "GrandmaUpgrades.h"

GrandmaUpgrades::GrandmaUpgrades(Grandma& existingGrandma) : grandmaRef(existingGrandma)
{
	getTotalApplesGained = existingGrandma.GetTotalApplesOverGame();

	exponentialRate = 7.0f;

	//for (int i = 0; i < 5; i++)
	//{
	//	upgradeMilestones[i] = std::pow(exponentialRate, i);
	//}

	//  Testing values
	upgradeMilestones[0] = 1;
	upgradeMilestones[1] = 3;
	upgradeMilestones[2] = 5;
	upgradeMilestones[3] = 6;
	upgradeMilestones[4] = 7;

	bUpgradeCompletion[0] = false;
	bUpgradeCompletion[1] = false;
	bUpgradeCompletion[2] = false;
	bUpgradeCompletion[3] = false;
	bUpgradeCompletion[4] = false;

	if (!upgradeTextures[0].loadFromFile("grandmaFirstTexture.png"))
	{
		std::cout << "Couldn't load 1st  upgrade textures\n";
	}
	if (!upgradeTextures[1].loadFromFile("grandmaSecondTexture.png"))
	{
		std::cout << "Couldn't load 2nd upgrade textures\n";
	}
	if (!upgradeTextures[2].loadFromFile("grandmaThirdTexture.png"))
	{
		std::cout << "Couldn't load 3rd upgrade textures\n";
	}
	if (!upgradeTextures[3].loadFromFile("grandmaFourthTexture.png"))
	{
		std::cout << "Couldn't load 4th upgrade textures\n";
	}
	if (!upgradeTextures[4].loadFromFile("grandmaFifthTexture.png"))
	{
		std::cout << "Couldn't load 5th upgades textures\n";
	}
}

void GrandmaUpgrades::Update(std::vector<sf::Sprite>& upgradeList)
{
	getTotalApplesGained = grandmaRef.GetTotalApplesOverGame();  // Update with current value
	AddToVector(upgradeList);
}
