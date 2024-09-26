#pragma once
#include "Item.h"
#include "originLocation.h"
#include "IStackable.h"

class CraftingMaterial :
    public Item, public IStackable
{
public :
    CraftingMaterial(std::string name, Texture2D image, std::string description, float weight, float price, int amount, originLocation originLocation);
    ~CraftingMaterial();
    void Craft();

protected:
    originLocation mOriginLoc;
};

