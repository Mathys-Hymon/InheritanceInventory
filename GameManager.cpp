#include "GameManager.h"

#include <iostream>

GameManager::GameManager()
{
	mButtonIndex = 0;
	mShowInventory = false;
	mInventoryTab = ItemTag::armor;
	mAllInventories[0] = Inventory(50, 100, ItemTag::armor);
	mAllInventories[1] = Inventory(20, 100, ItemTag::weapon);
	mAllInventories[2] = Inventory(30, 100, ItemTag::consumable);
	mAllInventories[3] = Inventory(25, 100, ItemTag::craftingItem);
	mInventoryButtons[0] = Buttons({ 95, 124, 215, 50}, BLUE, "Armor", BLACK, 25);
	mInventoryButtons[1] = Buttons({ 320, 124, 215, 50 }, BLUE, "Weapons", BLACK, 25);
	mInventoryButtons[2] = Buttons({ 545, 124, 215, 50 }, BLUE, "Consumable", BLACK, 25);
	mInventoryButtons[3] = Buttons({ 770, 124, 215, 50 }, BLUE, "Craft Objects", BLACK, 25);
	mInventoryButtons[mButtonIndex].SetButtonColor(DARKBLUE);

	mArmorItems[0] = {};
	mArmorItems[1] = {};
	mArmorItems[2] = {};
	mSword = {};
	mBow = {};
	mConsumableItems[0] = {};
	mConsumableItems[1] = {};
	mCraftingItems[0] = {};
	mCraftingItems[1] = {};

	mAllItems[0] = mArmorItems[0];
	mAllItems[1] = mArmorItems[1];
	mAllItems[2] = mArmorItems[2];
	mAllItems[3] = mSword;
	mAllItems[4] = mBow;
	mAllItems[5] = mConsumableItems[0];
	mAllItems[6] = mConsumableItems[1];
	mAllItems[7] = mCraftingItems[0];
	mAllItems[8] = mCraftingItems[1];
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	for (int i = 0; i < 4; i++) {
		mAllInventories[i].RefreshInventory();
	}
}

void GameManager::Update()
{
	if (IsKeyPressed(KEY_TAB)) {
		(mShowInventory == false) ? mShowInventory=true : mShowInventory=false;
		for (int i = 0; i < 4; i++) {
			mInventoryButtons[i].ResetTimer();
		}
	}
	if (mShowInventory) {
		mAllInventories[static_cast<int>(mInventoryTab)].Update();
		for (int i = 0; i < 4; i++) {
			mInventoryButtons[i].Update();
			if (mInventoryButtons[i].GetClickedBool()) {
				mInventoryButtons[i].SetButtonColor(DARKBLUE);
				mInventoryButtons[mButtonIndex].SetButtonColor(BLUE);
				mButtonIndex = i;
				mInventoryButtons[i].SetClickedBool(false);
				mInventoryTab = static_cast<ItemTag>(i);
			}
		}
	}
	else {
		for (int i = 0; i < 9; i++) {
			mAllItems[i]->Update();
			if (mAllItems[i]->GetIsClicked()) {
				mAllItems[i]->SetIsClicked(false);
				for (int j = 0; j < 4; j++) {
					if (mAllInventories[j].GetInventoryTag() == mAllItems[i]->GetTag()) {
						mAllInventories[j].AddItemToInventory(mAllItems[i]);
					}
				}
			}
		}
	}
}

void GameManager::Draw()
{
	if (mShowInventory) {
		mAllInventories[static_cast<int>(mInventoryTab)].Draw();
		for (int i = 0; i < 4; i++) {
			mInventoryButtons[i].Draw();
		}
	}
	else {
		for (int i = 0; i < 9; i++) {
			mAllItems[i]->Draw();
		}
	}
}

void GameManager::Unload()
{
	for (int i = 0; i < 4; i++) {
		mAllInventories[i].Unload();
	}
}
