#include "GameManager.h"

#include <iostream>

GameManager::GameManager()
{
	mButtonIndex = 0;
	mShowInventory = true;
	mInventoryTab = ItemTag::armor;
	mAllInventories[0] = Inventory(10, 100, ItemTag::armor);
	mAllInventories[1] = Inventory(10, 100, ItemTag::weapon);
	mAllInventories[2] = Inventory(20, 100, ItemTag::consumable);
	mAllInventories[3] = Inventory(22, 100, ItemTag::craftingItem);
	mInventoryButtons[0] = Buttons({ 95, 124, 215, 50}, BLUE, "Armor", BLACK, 25);
	mInventoryButtons[1] = Buttons({ 320, 124, 215, 50 }, BLUE, "Weapons", BLACK, 25);
	mInventoryButtons[2] = Buttons({ 545, 124, 215, 50 }, BLUE, "Consumable", BLACK, 25);
	mInventoryButtons[3] = Buttons({ 770, 124, 215, 50 }, BLUE, "Craft Objects", BLACK, 25);
	mInventoryButtons[mButtonIndex].SetButtonColor(DARKBLUE);
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	for (int i = 0; i < 4; i++) {
		mAllInventories[i].Load();
	}

	//Creating some Items just to debug

	mArmorItems[0] = new Armor("Draconic Helmet", LoadTexture("resources/textures/helmet.png"), "Lorem Ipsum", 10, 10, 1, ItemTag::armor, 21, ClassType::heavy);
	mArmorItems[1] = new Armor("Sacha's Jacket", LoadTexture("resources/textures/jacket.png"), "This is a super Jacket", 10, 10, 1, ItemTag::armor, 21, ClassType::heavy);
	mArmorItems[2] = new Armor("Sacha's Jacket", LoadTexture("resources/textures/jacket.png"), "This is a super Jacket", 10, 10, 1, ItemTag::armor, 21, ClassType::heavy);
	mArmorItems[3] = new Armor("Leggings", LoadTexture("resources/textures/pants.png"), "Good against Poison", 10, 10, 1, ItemTag::armor, 21, ClassType::heavy);
	mSword[0] = new Melee("Malenia's Sword", LoadTexture("resources/textures/catana.png"), "Malenia is really hard to beat", 2, 5, 1, ItemTag::weapon, 2, 3, 5);
	mSword[1] = new Melee("Malenia's Sword", LoadTexture("resources/textures/catana.png"), "Malenia is really hard to beat", 2, 5, 1, ItemTag::weapon, 2, 3, 5);
	mBow = new Ranged("Random Gun", LoadTexture("resources/textures/gun.png"), "Piou Piou", 4, 7, 1, 12, ItemTag::weapon, 2, 5);
	mConsumableItems[0] = new Consumable("Speed Soup", LoadTexture("resources/textures/soup.png"), "Miam", 77, 65, 50, ItemTag::consumable, EffectType::speed);
	mConsumableItems[1] = new Consumable("Sushi", LoadTexture("resources/textures/sushi.png"), "Best dish of the world ?", 3, 2, 1, ItemTag::consumable, EffectType::heal);
	mConsumableItems[2] = new Consumable("Sushi", LoadTexture("resources/textures/sushi.png"), "Best dish of the world ?", 3, 2, 1, ItemTag::consumable, EffectType::heal);
	mConsumableItems[3] = new Consumable("Sushi", LoadTexture("resources/textures/sushi.png"), "Best dish of the world ?", 3, 2, 1, ItemTag::consumable, EffectType::heal);
	mCraftingItems[0] = new CraftingMaterial("Leather", LoadTexture("resources/textures/leather.png"), "Usefull to make armors", 2, 3, 1, ItemTag::craftingItem, originLocation::mountains);
	mCraftingItems[1] = new CraftingMaterial("Star Fragment", LoadTexture("resources/textures/star.png"), "Easy to craft a beacon now", 2, 3, 1, ItemTag::craftingItem, originLocation::mountains);
	mCraftingItems[2] = new CraftingMaterial("Star Fragment", LoadTexture("resources/textures/star.png"), "Easy to craft a beacon now", 2, 3, 1, ItemTag::craftingItem, originLocation::mountains);
	mCraftingItems[3] = new CraftingMaterial("Star Fragment", LoadTexture("resources/textures/star.png"), "Easy to craft a beacon now", 2, 3, 1, ItemTag::craftingItem, originLocation::mountains);
	mCraftingItems[4] = new CraftingMaterial("Star Fragment", LoadTexture("resources/textures/star.png"), "Easy to craft a beacon now", 2, 3, 1, ItemTag::craftingItem, originLocation::mountains);

	mAllItems[0] = mArmorItems[0];
	mAllItems[1] = mArmorItems[1];
	mAllItems[2] = mArmorItems[2];
	mAllItems[3] = mArmorItems[3];
	mAllItems[4] = mSword[0];
	mAllItems[5] = mSword[1];
	mAllItems[6] = mBow;
	mAllItems[7] = mConsumableItems[0];
	mAllItems[8] = mConsumableItems[1];
	mAllItems[9] = mConsumableItems[2];
	mAllItems[10] = mConsumableItems[3];
	mAllItems[11] = mCraftingItems[0];
	mAllItems[12] = mCraftingItems[1];
	mAllItems[13] = mCraftingItems[2];
	mAllItems[14] = mCraftingItems[3];
	mAllItems[15] = mCraftingItems[4];

	for (int i = 0; i < sizeof(mAllItems) / sizeof(mAllItems[0]); i++) {
		for (int j = 0; j < 4; j++) {
			if (mAllInventories[j].GetInventoryTag() == mAllItems[i]->GetTag()) {
				mAllInventories[j].AddItemToInventory(mAllItems[i]);
			}
		}
	}

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
				mInventoryButtons[i].SetClickedBool(false);
				mInventoryButtons[i].SetButtonColor(DARKBLUE);
				mInventoryButtons[mButtonIndex].SetButtonColor(BLUE);
				mAllInventories[mButtonIndex].SetShowActionBtn(false);
				mAllInventories[mButtonIndex].SetShowItemInfos(false);
				mAllInventories[mButtonIndex].SetShowText(false);
				mButtonIndex = i;
				mInventoryTab = static_cast<ItemTag>(i);
				mAllInventories[static_cast<int>(mInventoryTab)].SetInfoIndex(0);
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
}

void GameManager::Unload()
{
	for (int i = 0; i < 4; i++) {
		mAllInventories[i].Unload();
	}
	for (int j = 0; j < sizeof(mAllItems) / sizeof(mAllItems[0]); j++) {
		mAllItems[j]->Unload();
	}
}
