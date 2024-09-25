#include "Inventory.h"

Inventory::Inventory()
{
	mMaxSlots = 0;
	mItemStorage = new Item*[0];
	mMaxItemPerStack = 0;
}

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
	}
}

void Inventory::Draw()
{
	DrawRectangle(GetScreenWidth() / 2 - 450, GetScreenHeight() / 2 - 300, 900, 600, WHITE);
	for (int i = 0; i < mMaxSlots; i++) {

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
