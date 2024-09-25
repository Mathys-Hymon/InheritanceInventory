#pragma once
#include "Weapon.h"
class Ranged :
    public Weapon
{
public:
    Ranged();
    ~Ranged();
    void Aim();
    void Reload();

protected:
    int mAmmo;
};

