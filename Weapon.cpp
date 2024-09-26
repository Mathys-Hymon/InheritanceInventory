#include "Weapon.h"

Weapon::Weapon(std::string name, Texture2D image, std::string description, float weight, float price, int amount, float damages, float attackSpeed) : Item(name, image, description, weight, price, amount)
{
    mDamages = damages;
    mAttackSpeed = attackSpeed;
}

Weapon::~Weapon()
{
}

float Weapon::Attack()
{
    return mDamages;
}
