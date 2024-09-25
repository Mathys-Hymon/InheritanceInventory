#pragma once
#include "raylib.h"
#include "Item.h"

class Inventory
{
public:
	Inventory(int maxSlots, int maxItemPerStack);
	~Inventory();
	void Update();
	void Draw();
	void AddItemToInventory(Item* itemToAdd);
private:
	int mMaxSlots;
	int mMaxItemPerStack;
	Item** mItemStorage;
};

