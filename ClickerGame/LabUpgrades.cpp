#include "LabUpgrades.h"

LabUpgrades::LabUpgrades(Lab& existingLab) : labRef(existingLab)
{
	getTotalApplesGained = labRef.GetTotalApplesOverGame();

	exponentialRate = 5.0f;

	//for (int i = 0; i < 5; i++)
	//{
	//	upgradeMilestones[i] = std::pow(exponentialRate, i);
	//}

	//  Testing values
	upgradeMilestones[0] = 0.1;
	upgradeMilestones[1] = 0.3;
	upgradeMilestones[2] = 0.5;
	upgradeMilestones[3] = 0.7;
	upgradeMilestones[4] = 0.9;

	bUpgradeCompletion[0] = false;
	bUpgradeCompletion[1] = false;
	bUpgradeCompletion[2] = false;
	bUpgradeCompletion[3] = false;
	bUpgradeCompletion[4] = false;

	if (!upgradeTextures[0].loadFromFile("labFirstTexture.png"))
	{
		std::cout << "Couldn't load 1st  upgrade textures\n";
	}
	if (!upgradeTextures[1].loadFromFile("labSecondTexture.png"))
	{
		std::cout << "Couldn't load 2nd upgrade textures\n";
	}
	if (!upgradeTextures[2].loadFromFile("labThirdTexture.png"))
	{
		std::cout << "Couldn't load 3rd upgrade textures\n";
	}
	if (!upgradeTextures[3].loadFromFile("labFourthTexture.png"))
	{
		std::cout << "Couldn't load 4th upgrade textures\n";
	}
	if (!upgradeTextures[4].loadFromFile("labFifthTexture.png"))
	{
		std::cout << "Couldn't load 5th upgades textures\n";
	}
}

void LabUpgrades::Update(std::vector<sf::Sprite>& upgradeList)
{
	getTotalApplesGained = labRef.GetTotalApplesOverGame();
	AddToVector(upgradeList);
}