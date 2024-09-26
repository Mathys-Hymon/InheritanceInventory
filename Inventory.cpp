#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	mMaxSlots = 0;
	mItemStorage = new Item*[0];
	mInventorySlots = new Buttons[0];
	mMaxItemPerStack = 0;
	mInventoryTag = ItemTag::armor;
}

Inventory::Inventory(int maxSlots, int maxItemPerStack, ItemTag tag)
{
	mMaxSlots = maxSlots;
	mItemStorage = new Item*[maxSlots];
	mInventorySlots = new Buttons[maxSlots];
	mMaxItemPerStack = maxItemPerStack;
	Texture2D texture = Texture2D();
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
			mInventorySlots[maxSlots-slotsRemaining] = Buttons({ spaceX + (190 / 2), spaceY + (424 / 2), 80, 80 }, WHITE, texture, 1);
			slotsRemaining -= 1;
		}
	}

	for (int i = 0; i < maxSlots; i++)
	{
		mItemStorage[i] = nullptr;
	}

	mInventoryTag = tag;
	mShowInfosIndex = 0;
}

Inventory::~Inventory()
{
}

void Inventory::Update()
{
	for (int i = 0; i < mMaxSlots; i++) {
		mInventorySlots[i].Update();
		if (mInventorySlots[i].GetClickedBool()) {
			mInventorySlots[i].SetClickedBool(false);
			mShowInfosIndex = i;
		}
	}
}

void Inventory::Draw()
{
	DrawRectangle(GetScreenWidth() / 2 - 460, GetScreenHeight() / 2 - 300, 920, 600, WHITE);
	DrawRectangleLinesEx({ 735, 400, 250, 250 }, 4, BLACK);
	for (int i = 0; i < mMaxSlots; i++) {
		mInventorySlots[i].Draw();
		if (mItemStorage[i] != nullptr) {
			if (mItemStorage[i]->GetAmount() > 1) {
				DrawText(TextFormat("x%i", mItemStorage[i]->GetAmount()), mInventorySlots[i].GetButtonPosition().x + mInventorySlots[i].GetSize().x - MeasureText(TextFormat("x%i", mItemStorage[i]->GetAmount()), 20) - 4, mInventorySlots[i].GetButtonPosition().y + mInventorySlots[i].GetSize().y - 21, 20, BLACK);
			}
		}
	}
	Texture2D texture = *mItemStorage[mShowInfosIndex]->GetImage();
	texture.width = 250;
	texture.height = 250;
	DrawTexture(texture, 735, 400, WHITE);
	DrawText(mItemStorage[mShowInfosIndex]->GetName().c_str(), 700 - MeasureText(mItemStorage[mShowInfosIndex]->GetName().c_str(), 40), 550, 40, BLACK);
	DrawText(mItemStorage[mShowInfosIndex]->GetDesc().c_str(), 700 - MeasureText(mItemStorage[mShowInfosIndex]->GetDesc().c_str(), 30), 610, 30, BLACK);
}

void Inventory::AddItemToInventory(Item* itemToAdd)
{
	for (int i = 0; i < mMaxSlots; i++) {
		if (mItemStorage[i] != nullptr) {
			if (mItemStorage[i]->GetName() == itemToAdd->GetName()) {
				if (mItemStorage[i]->GetAmount() < mMaxItemPerStack) {
					IStackable* itemStackable = dynamic_cast<IStackable*>(mItemStorage[i]);
					if (itemStackable != nullptr) {
						itemStackable->Add(1);
						break;
					}
				}
			}
		}
		else {
			mItemStorage[i] = itemToAdd;
			mInventorySlots[i].SetTexture(itemToAdd->GetImage(), 1);
			RefreshInventory();
			break;
		}
	}
}

void Inventory::Unload()
{
	for (int i = 0; i < mMaxSlots; i++) {
		mInventorySlots[i].Unload();
	}
}

void Inventory::RefreshInventory()
{
	for (int i = 0; i < mMaxSlots; i++) {
		auto item = mItemStorage[i];
		if (item == nullptr){
			mInventorySlots[i].SetEnable(false);
		}
		else {
			mInventorySlots[i].SetEnable(true);
		}
	}
}

ItemTag Inventory::GetInventoryTag()
{
	return mInventoryTag;
}
