#pragma once
#include "Weapon.h"
class Ranged :
    public Weapon
{
public:
    Ranged();
    Ranged(std::string name, Texture2D image, std::string description, float weight, float price, int amount, float damages, ItemTag tag, float attackSpeed, float ammo);
    ~Ranged();
    void Aim();
    void Reload();

protected:
    int mAmmo;
};

