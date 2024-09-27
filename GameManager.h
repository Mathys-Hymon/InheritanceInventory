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

	Item* mAllItems[16];

	Armor* mArmorItems[4];
	Melee* mSword[2];
	Ranged* mBow;
	Consumable* mConsumableItems[4];
	CraftingMaterial* mCraftingItems[5];

	int mButtonIndex;
};

