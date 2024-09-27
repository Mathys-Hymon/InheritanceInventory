#pragma once
#include "Item.h"
#include "IEquippable.h"

class Weapon :
    public Item, public IEquippable
{
public:
    Weapon();
    Weapon(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, float damages,float attackSpeed);
    ~Weapon();
    float Attack();
    void Equip();

protected :
    float mDamages;
    float mAttackSpeed;
};

