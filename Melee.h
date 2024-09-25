#pragma once
#include "Weapon.h"
class Melee :
    public Weapon
{
public:
    Melee();
    ~Melee();
    void Parry();

protected:
    float mAttackRange;
};

