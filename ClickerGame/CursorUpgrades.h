#pragma once
#include "Upgrades.h"
#include "Cursor.h"
#include <math.h>

class CursorUpgrades : public Upgrades
{
public:
	CursorUpgrades(Cursor& existingCursor);
	void Update(std::vector<sf::Sprite>& upgradeList);

private:
	ClickObject apple;
	Cursor& cursorRef;
};