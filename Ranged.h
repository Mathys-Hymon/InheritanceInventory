#pragma once
#include "Weapon.h"
class Ranged :
    public Weapon
{
public:
    void Aim();
    void Reload();

protected:
    int mAmmo;
};

