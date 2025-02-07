#pragma once
#include "Upgrades.h"
#include "Grandma.h"
#include "math.h"

class GrandmaUpgrades : public Upgrades
{
public:
	GrandmaUpgrades(Grandma& existingGrandma);
	void Update(std::vector<sf::Sprite>& upgradeList);

private:
	ClickObject apple;
	Grandma& grandmaRef;
};

