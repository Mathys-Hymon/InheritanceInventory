#include "GameManager.h"

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

void GameManager::Update()
{
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
