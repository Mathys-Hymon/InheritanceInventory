#include "GameManager.h"

#include <iostream>

GameManager::GameManager()
{
	mShowInventory = true;
	inventoryTab = ItemTag::armor;
	allInventories[0] = Inventory(50, 100);
	allInventories[1] = Inventory(20, 100);
	allInventories[2] = Inventory(20, 100);
	allInventories[3] = Inventory(20, 100);
}

GameManager::~GameManager()
{
}

void GameManager::Load()
{
	for (int i = 0; i < 4; i++) {
		allInventories[i].RefreshInventory();
	}
}

void GameManager::Update()
{
	if (IsKeyPressed(KEY_TAB)) {
		(mShowInventory == false) ? mShowInventory=true : mShowInventory=false;
	}
	if (mShowInventory) {
		allInventories[static_cast<int>(inventoryTab)].Update();
	}
}

void GameManager::Draw()
{
	if (mShowInventory) {
		allInventories[static_cast<int>(inventoryTab)].Draw();
	}	
}

void GameManager::Unload()
{
	for (int i = 0; i < 4; i++) {
		allInventories[i].Unload();
	}
}
