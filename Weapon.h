#pragma once
#include "Item.h"

class Weapon :
    public Item
{
public:
    Weapon();
    ~Weapon();
    float Attack();

protected :
    float mDamages;
    float mAttackSpeed;
};

