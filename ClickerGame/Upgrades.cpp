#include "Upgrades.h"

Upgrades::Upgrades()
{
	getTotalApplesGained = {};
}

// TODO: FIGURE OUT WHY THE SPRITES ARENT BEING ADDED CORRECTLY

void Upgrades::AddToVector(std::vector<sf::Sprite>& upgradeList)
{
	//std::cout << getTotalApplesGained << '\n';
	if (getTotalApplesGained >= upgradeMilestones[0] && bUpgradeCompletion[0] == false)
	{
		sf::Sprite upgradeSprite1;
		upgradeSprite1.setTexture(upgradeTextures[0]);
		upgradeList.push_back(upgradeSprite1);
		bUpgradeCompletion[0] = true;
		std::cout << "Added first upgrade to vector\n";
		std::cout << upgradeList.size() << '\n';
	}

	if (getTotalApplesGained >= upgradeMilestones[1] && bUpgradeCompletion[1] == false)
	{
		sf::Sprite upgradeSprite2;
		upgradeSprite2.setTexture(upgradeTextures[1]);
		upgradeList.push_back(upgradeSprite2);
		bUpgradeCompletion[1] = true;
		std::cout << "Added second upgrade to vector\n";
		std::cout << upgradeList.size() << '\n';
	}

	if (getTotalApplesGained >= upgradeMilestones[2] && bUpgradeCompletion[2] == false)
	{
		sf::Sprite upgradeSprite3;
		upgradeSprite3.setTexture(upgradeTextures[2]);
		upgradeList.push_back(upgradeSprite3);
		bUpgradeCompletion[2] = true;
		std::cout << "Added third upgrade to vector\n";
	}

	if (getTotalApplesGained >= upgradeMilestones[3] && bUpgradeCompletion[3] == false)
	{
		sf::Sprite upgradeSprite4;
		upgradeSprite4.setTexture(upgradeTextures[3]);
		upgradeList.push_back(upgradeSprite4);
		bUpgradeCompletion[3] = true;
		std::cout << "Added fourth upgrade to vector\n";
	}

	if (getTotalApplesGained >= upgradeMilestones[4] && bUpgradeCompletion[4] == false)
	{
		sf::Sprite upgradeSprite5;
		upgradeSprite5.setTexture(upgradeTextures[4]);
		upgradeList.push_back(upgradeSprite5);
		bUpgradeCompletion[4] = true;
		std::cout << "Added fifth upgrade to vector\n";
	}
}

void Upgrades::Update(std::vector<sf::Sprite>& upgradeList)
{
	std::cout << GetTotalApplesFromThisPowerup() << '\n';
	AddToVector(upgradeList);
}
