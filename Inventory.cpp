#include "Inventory.h"

Inventory::Inventory(int maxSlots, int maxItemPerStack)
{
	mMaxSlots = maxSlots;
	mItemStorage = new Item*[maxSlots];
	mMaxItemPerStack = maxItemPerStack;
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
		if (mItemStorage[i]->GetName() == itemToAdd->GetName()) {
			if (mItemStorage[i]->GetAmount() < mMaxItemPerStack) {
				mItemStorage[i]->
			}
		}
	}
}
