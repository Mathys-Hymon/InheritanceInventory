#pragma once
#include "raylib.h"
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

protected:
	std::string mName;
	Texture2D mImage;
	std::string mDescription;
	std::string mTag;
	float mWeight;
	float mPrice;
	int mAmount;
};