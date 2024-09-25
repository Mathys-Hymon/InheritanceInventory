#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	mMaxSlots = 0;
	mItemStorage = new Item*[0];
	mInventorySlots = new Rectangle[0];
	mMaxItemPerStack = 0;
}

Inventory::Inventory(int maxSlots, int maxItemPerStack)
{
	mMaxSlots = maxSlots;
	mItemStorage = new Item*[maxSlots];
	mInventorySlots = new Rectangle[maxSlots];
	mMaxItemPerStack = maxItemPerStack;
	int slotsRemaining = maxSlots;
	int row = 0;
	if (mMaxSlots % 10 > 0) {
		row = mMaxSlots / 10 + 1;
	}
	else {
		row = mMaxSlots / 10;
	}
	for (int j = 0; j < row; j++) {
		int columns = (slotsRemaining >= 10) ? columns = 10 : columns = slotsRemaining;
		for (int i = 0; i < columns; i++) {
			float spaceX = 90 * i;
			float spaceY = 90 * j;
			mInventorySlots[maxSlots-slotsRemaining] = {spaceX + (190/2), spaceY + (424/2), 80, 80};
			slotsRemaining -= 1;
		}
	}

}

Inventory::~Inventory()
{
}

void Inventory::Update()
{

	for (int i = 0; i < mMaxSlots; i++) {
	}
}

void Inventory::Draw()
{
	DrawRectangle(GetScreenWidth() / 2 - 460, GetScreenHeight() / 2 - 300, 920, 600, WHITE);
	for (int i = 0; i < mMaxSlots; i++) {
		DrawRectangle(mInventorySlots[i].x, mInventorySlots[i].y, mInventorySlots[i].width, mInventorySlots[i].height, GRAY);
	}
}

void Inventory::AddItemToInventory(Item* itemToAdd)
{
	for (int i = 0; i < mMaxSlots; i++) {
		if (mItemStorage[i]->GetName() == itemToAdd->GetName()) {
			if (mItemStorage[i]->GetAmount() < mMaxItemPerStack) {
				IStackable* itemStackable = dynamic_cast<IStackable*>(mItemStorage[i]);
				if (itemStackable != nullptr) {
					itemStackable->Add(1);
					break;
				}
			}
		}
		if (mItemStorage[i] == nullptr) {
			mItemStorage[i] = itemToAdd;
		}
	}
}
