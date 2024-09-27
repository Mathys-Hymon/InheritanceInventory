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
	mActionsBtn[0] = Buttons({ 0, 0, 200, 50 }, WHITE, "Drop", BLACK, 20);
	mActionsBtn[1] = Buttons({ 0, 0, 200, 50 }, WHITE, "Inspect", BLACK, 20);
	mActionsBtn[2] = Buttons({ 0, 0, 200, 50 }, WHITE, "Sell", BLACK, 20);
	mActionsBtn[3] = Buttons({ 0, 0, 200, 50 }, WHITE, "Favorite", BLACK, 20);
	mShowActionBtn = false;
}

Inventory::~Inventory()
{
}

void Inventory::Load()
{
	mFavoriteTexture = LoadTexture("resources/textures/favorite.png");
	mFavoriteTexture.width = 20;
	mFavoriteTexture.height = 20;
}

void Inventory::Update()
{
	for (int i = 0; i < mMaxSlots; i++) {
		mInventorySlots[i].Update();
		if (mInventorySlots[i].GetClickedBool()) {
			mInventorySlots[i].SetClickedBool(false);
			if (mShowInfosIndex == i && mShowActionBtn) {
				mShowActionBtn = false;
			}
			else {
				mShowActionBtn = true;
			}
			mShowInfosIndex = i;
			for (int j = 0; j < 4; j++) {
				mActionsBtn[j].SetButtonPosition({ mInventorySlots[i].GetButtonPosition().x, mInventorySlots[i].GetButtonPosition().y + 80 + 50*j});
			}
		}
	}
	if (mShowActionBtn) {
		for (int i = 0; i < 4; i++) {
			mActionsBtn[i].Update();
		}
		if (mActionsBtn[0].GetClickedBool()) {
			mActionsBtn[0].SetClickedBool(false);
			mItemStorage[mShowInfosIndex]->Drop(1);
			RefreshInventory();
		}
		if (mActionsBtn[2].GetClickedBool()) {
			mActionsBtn[2].SetClickedBool(false);
			mItemStorage[mShowInfosIndex]->Sell();
			RefreshInventory();
		}
		if (mActionsBtn[3].GetClickedBool()) {
			mActionsBtn[3].SetClickedBool(false);
			mItemStorage[mShowInfosIndex]->Favorite();
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
			if (mItemStorage[i]->GetIsFavorited()) {
				DrawTexture(mFavoriteTexture, mInventorySlots[i].GetButtonPosition().x + 2, mInventorySlots[i].GetButtonPosition().y + 2, WHITE);
			}
		}
	}
	if (mItemStorage[mShowInfosIndex] != nullptr) {
		Texture2D texture = *mItemStorage[mShowInfosIndex]->GetImage();
		texture.width = 250;
		texture.height = 250;
		DrawTexture(texture, 735, 400, WHITE);
		DrawText(mItemStorage[mShowInfosIndex]->GetName().c_str(), 700 - MeasureText(mItemStorage[mShowInfosIndex]->GetName().c_str(), 40), 550, 40, BLACK);
		DrawText(mItemStorage[mShowInfosIndex]->GetDesc().c_str(), 700 - MeasureText(mItemStorage[mShowInfosIndex]->GetDesc().c_str(), 30), 610, 30, BLACK);
	}
	if (mShowActionBtn) {
		for (int i = 0; i < 4; i++) {
			mActionsBtn[i].Draw();
		}
	}
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
	UnloadTexture(mFavoriteTexture);
}

void Inventory::RefreshInventory()
{
	for (int i = 0; i < mMaxSlots; i++) {
		if (mItemStorage[i] != nullptr) {
			if (mItemStorage[i]->GetAmount() <= 0) {
				mItemStorage[i] = nullptr;
				mInventorySlots[i].SetTexture(new Texture2D(), 1);
				mShowActionBtn = false;
				break;
			}
		}
	}
	for (int i = 0; i < mMaxSlots; i++) {
		if (mItemStorage[i] == nullptr){
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

void Inventory::SetInfoIndex(int newIndex)
{
	mShowInfosIndex = newIndex;
}

void Inventory::SetShowActionBtn(bool newState)
{
	mShowActionBtn = newState;
}
