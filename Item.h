#pragma once
#include "raylib.h"
#include "ItemTag.h"
#include <iostream>

 class Item
{
public:
	Item(std::string name, Texture2D image, std::string description, float weight, float price, int amount);
	~Item();
	void Drop(int quantity);
	void Inspect();
	void Sell();
	void Favorite();

	std::string GetName();
	std::string GetDesc();
	int GetPrice();
	ItemTag GetTag();
	Texture2D GetImage();

protected:
	std::string mName;
	Texture2D mImage;
	std::string mDescription;
	ItemTag mTag;
	float mWeight;
	float mPrice;
};