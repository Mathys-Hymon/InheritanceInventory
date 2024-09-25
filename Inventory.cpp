#include "Inventory.h"

Inventory::Inventory(int maxSlots)
{
	mMaxSlots = maxSlots;
	mItemStorage = new Item*[maxSlots];
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{

	for (int i = 0; i < mMaxSlots; i++) {
		mItemStorage[i]->Inspect();
	}
}

void Inventory::Draw()
{
}

void Inventory::AddItemToInventory(Item* itemToAdd)
{
	for (int i = 0; i < mMaxSlots; i++) {
		if(mItemStorage[i])
	}
}
