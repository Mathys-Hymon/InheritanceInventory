#pragma once
#include "raylib.h"
#include "Item.h"

class Inventory
{
public:
	Inventory(int maxSlots);
	~Inventory();
	void Update();
	void Draw();
	void AddItemToInventory(Item* itemToAdd);
private:
	int mMaxSlots;
	Item** mItemStorage;
};

