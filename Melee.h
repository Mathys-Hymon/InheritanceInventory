#pragma once
#include "Weapon.h"
class Melee :
    public Weapon
{
public:
    Melee(std::string name, Texture2D image, std::string description, float weight, float price, int amount,float damage, float attackSpeed, float attackRange);
    ~Melee();
    void Parry();

protected:
    float mAttackRange;
};

