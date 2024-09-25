#pragma once
#include "raylib.h"
#include "Inventory.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	void Load();
	void Update();
	void Draw();
	void Unload();
private:
	bool mShowInventory;
	ItemTag inventoryTab;
	Inventory allInventories[4];
};

