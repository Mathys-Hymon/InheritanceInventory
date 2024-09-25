#pragma once
#include "raylib.h"
#include "Item.h"
#include "IStackable.h"

class Inventory
{
public:
	Inventory();
	Inventory(int maxSlots, int maxItemPerStack);
	~Inventory();
	void Update();
	void Draw();
	void AddItemToInventory(Item* itemToAdd);
private:
	int mMaxSlots;
	int mMaxItemPerStack;
	Rectangle* mInventorySlots;
	Item** mItemStorage;
};

