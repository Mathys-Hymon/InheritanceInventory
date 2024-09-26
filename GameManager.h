#pragma once
#include "raylib.h"
#include "Inventory.h"
#include "Armor.h"
#include "Melee.h"
#include "Ranged.h"
#include "Consumable.h"
#include "CraftingMaterial.h"
#include "Buttons.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Load();
	void Update();
	void Draw();
	void Unload();
private:
	bool mShowInventory;
	ItemTag mInventoryTab;
	Inventory mAllInventories[4];
	Buttons mInventoryButtons[4];

	Item* mAllItems[9];

	Armor* mArmorItems[3];
	Melee* mSword;
	Ranged* mBow;
	Consumable* mConsumableItems[2];
	CraftingMaterial* mCraftingItems[2];

	int mButtonIndex;
};

