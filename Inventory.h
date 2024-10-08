#pragma once
#include "raylib.h"
#include "Item.h"
#include "IStackable.h"
#include "IEquippable.h"
#include "ItemTag.h"
#include "Buttons.h"
#include "PlayerStats.h"
#include <sstream>

class Inventory
{
public:
	Inventory();
	Inventory(int maxSlots, int maxItemPerStack, ItemTag tag);
	~Inventory();
	void Load();
	void Update();
	void Draw();
	void AddItemToInventory(Item* itemToAdd);
	void Unload();
	void RefreshInventory();
	ItemTag GetInventoryTag();
	void SetInfoIndex(int newIndex);
	void SetShowActionBtn(bool newState);
	void SetShowItemInfos(bool newState);
	void SetShowText(bool newState);

private:
	int mMaxSlots;
	int mMaxItemPerStack;
	Buttons* mInventorySlots;
	Item** mItemStorage;
	ItemTag mInventoryTag;
	int mShowInfosIndex;
	int mSlotSelected;
	bool mShowItemInfos;
	Buttons mActionsBtn[5];
	bool mShowActionBtn;
	Texture2D mFavoriteTexture;

	float mTextTimer;
	float mOpacityMultiplier;
	Color mTextColor;
	std::string mText;
	bool mShowText;
};

