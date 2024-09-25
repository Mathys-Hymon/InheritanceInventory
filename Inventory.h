#pragma once
#include "raylib.h"
#include "Item.h"
#include "IStackable.h"
#include "Buttons.h"

class Inventory
{
public:
	Inventory();
	Inventory(int maxSlots, int maxItemPerStack);
	~Inventory();
	void Update();
	void Draw();
	void AddItemToInventory(Item* itemToAdd);
	void Unload();
	void RefreshInventory();
private:
	int mMaxSlots;
	int mMaxItemPerStack;
	Buttons* mInventorySlots;
	Item** mItemStorage;
};

