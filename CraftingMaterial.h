#pragma once
#include "Item.h"
#include "originLocation.h"

class CraftingMaterial :
    public Item
{
public :
    CraftingMaterial();
    ~CraftingMaterial();
    void Craft();

protected:
    originLocation originLoc;
};

