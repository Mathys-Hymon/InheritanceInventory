#pragma once
#include "Item.h"
#include "originLocation.h"

class CraftingMaterial :
    public Item
{
public :
    void Craft();

protected:
    originLocation originLoc;
};

