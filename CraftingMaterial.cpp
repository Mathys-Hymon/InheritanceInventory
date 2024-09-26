#include "CraftingMaterial.h"

CraftingMaterial::CraftingMaterial(std::string name, Texture2D image, std::string description, float weight, float price, int amount, originLocation originLocation): Item(name, image, description, weight, price, amount)
{
	mOriginLoc = originLocation;
}

CraftingMaterial::~CraftingMaterial()
{
}

void CraftingMaterial::Craft()
{
}
