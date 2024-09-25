#pragma once
#include "Item.h"
#include "ArmorType.h"

class Armor :
    public Item
{
protected:
    float mDefense;
    ClassType mClass;
};

