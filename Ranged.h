#pragma once
#include "Weapon.h"
class Ranged :
    public Weapon
{
public:
    Ranged(std::string name, Texture2D image, std::string description, float weight, float price, int amount, float ammo);
    ~Ranged();
    void Aim();
    void Reload();

protected:
    int mAmmo;
};

