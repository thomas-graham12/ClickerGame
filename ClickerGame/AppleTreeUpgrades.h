#pragma once
#include "Upgrades.h"
#include "AppleTree.h"
#include <math.h>

class AppleTreeUpgrades : public Upgrades
{
public:
	AppleTreeUpgrades(AppleTree& existingAppleTree);
	void Update(std::vector<sf::Sprite>& upgradeList);

private:
	ClickObject apple;
	AppleTree& appleTreeRef;
};

