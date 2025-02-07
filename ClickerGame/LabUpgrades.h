#pragma once
#include "Upgrades.h"
#include "Lab.h"
#include <math.h>

class LabUpgrades : public Upgrades
{
public:
	LabUpgrades(Lab& existingLab);
	void Update(std::vector<sf::Sprite>& upgradeList);

private:
	ClickObject apple;
	Lab& labRef;
};

