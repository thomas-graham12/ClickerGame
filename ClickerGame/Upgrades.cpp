#include "Upgrades.h"

Upgrades::Upgrades()
{
	getTotalApplesGained = {};
}

void Upgrades::AddToVector(std::vector<sf::Sprite>& upgradeList)
{
	// TODO: MAKE IT SO THE VECTOR CAN ONLY HAVE 5 AT A TIME
	//std::cout << getTotalApplesGained << '\n';
	if (upgradeList.size() >= 5)
	{
		std::cout << "cannot add anything else to the list\n";
	}
	else
	{
		if (getTotalApplesGained >= upgradeMilestones[0] && bUpgradeCompletion[0] == false)
		{
			spriteToAddToVector.setTexture(upgradeTextures[0]);
			//spriteToAddToVector.setPosition(190.0f, 560.0f);
			//spriteToAddToVector.setScale(0.3f, 0.3f);
			upgradeList.emplace_back(spriteToAddToVector);
			bUpgradeCompletion[0] = true;
			std::cout << "Added first upgrade to vector\n";
			//std::cout << upgradeList.size() << '\n';
		}

		if (getTotalApplesGained >= upgradeMilestones[1] && bUpgradeCompletion[1] == false)
		{
			spriteToAddToVector.setTexture(upgradeTextures[1]);
			//spriteToAddToVector.setPosition(340.0f, 560.0f);
			//spriteToAddToVector.setScale(0.3f, 0.3f);
			upgradeList.emplace_back(spriteToAddToVector);
			bUpgradeCompletion[1] = true;
			std::cout << "Added second upgrade to vector\n";
			//std::cout << upgradeList.size() << '\n';
		}

		if (getTotalApplesGained >= upgradeMilestones[2] && bUpgradeCompletion[2] == false)
		{
			spriteToAddToVector.setTexture(upgradeTextures[2]);
			//spriteToAddToVector.setPosition(490.0f, 560.0f);
			//spriteToAddToVector.setScale(0.3f, 0.3f);
			upgradeList.emplace_back(spriteToAddToVector);
			bUpgradeCompletion[2] = true;
			std::cout << "Added third upgrade to vector\n";
		}

		if (getTotalApplesGained >= upgradeMilestones[3] && bUpgradeCompletion[3] == false)
		{
			spriteToAddToVector.setTexture(upgradeTextures[3]);
			//spriteToAddToVector.setPosition(640.0f, 560.0f);
			//spriteToAddToVector.setScale(0.3f, 0.3f);
			upgradeList.emplace_back(spriteToAddToVector);
			bUpgradeCompletion[3] = true;
			std::cout << "Added fourth upgrade to vector\n";
		}

		if (getTotalApplesGained >= upgradeMilestones[4] && bUpgradeCompletion[4] == false)
		{
			spriteToAddToVector.setTexture(upgradeTextures[4]);
			//spriteToAddToVector.setPosition(790.0f, 560.0f);
			//spriteToAddToVector.setScale(0.3f, 0.3f);
			upgradeList.emplace_back(spriteToAddToVector);
			bUpgradeCompletion[4] = true;
			std::cout << "Added fifth upgrade to vector\n";
		}
	}
	
}

void Upgrades::Update(std::vector<sf::Sprite>& upgradeList)
{
	//std::cout << GetTotalApplesFromThisPowerup() << '\n';
	AddToVector(upgradeList);
}
