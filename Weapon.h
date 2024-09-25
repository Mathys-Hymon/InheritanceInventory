#pragma once
#include "Item.h"

class Weapon :
    public Item
{
public:
    float Attack();

protected :
    float mDamages;
    float mAttackSpeed;
};

