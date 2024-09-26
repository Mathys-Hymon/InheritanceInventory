#pragma once
#include "Item.h"
#include "originLocation.h"

class CraftingMaterial :
    public Item, public IStackable
{
public :
    CraftingMaterial();
    ~CraftingMaterial();
    void Craft();

protected:
    originLocation originLoc;
};

