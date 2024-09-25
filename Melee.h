#pragma once
#include "Weapon.h"
class Melee :
    public Weapon
{
public:
    void Parry();

protected:
    float mAttackRange;
};

