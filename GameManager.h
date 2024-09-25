#pragma once
#include "raylib.h"
#include "Inventory.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Update();
	void Draw();
private:
	bool mShowInventory;
	ItemTag inventoryTab;
	Inventory allInventories[4];
};

