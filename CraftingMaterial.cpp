#include "CraftingMaterial.h"

CraftingMaterial::CraftingMaterial() : Item()
{
}

CraftingMaterial::CraftingMaterial(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, originLocation originLocation): Item(name, image, description, weight, price, amount, tag)
{
	mOriginLoc = originLocation;
}

CraftingMaterial::~CraftingMaterial()
{
}

void CraftingMaterial::Craft()
{
}

void CraftingMaterial::Add(int amount)
{
}
