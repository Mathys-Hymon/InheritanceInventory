#pragma once
#include "Item.h"
#include "originLocation.h"
#include "IStackable.h"

class CraftingMaterial :
    public Item, public IStackable
{
public :
    CraftingMaterial();
    CraftingMaterial(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, originLocation originLocation);
    ~CraftingMaterial();
    void Craft();
    void Add(int amount);

protected:
    originLocation mOriginLoc;
};

