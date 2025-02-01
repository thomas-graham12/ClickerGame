#pragma once
#include "Upgrades.h"
#include "Cursor.h"

class CursorUpgrades : public Upgrades
{
public:
	CursorUpgrades();
	void UpdateApples();

private:
	ClickObject apple;
};