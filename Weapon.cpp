#include "Weapon.h"

Weapon::Weapon() : Item()
{
}

Weapon::Weapon(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, float damages, float attackSpeed) : Item(name, image, description, weight, price, amount, tag)
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

void Weapon::Equip()
{
}
