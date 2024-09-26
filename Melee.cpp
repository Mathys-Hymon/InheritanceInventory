#include "Melee.h"

Melee::Melee() : Weapon()
{
}

Melee::Melee(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, float damage, float attackSpeed, float attackRange) : Weapon(name, image, description, weight, price, amount,tag, damage, attackSpeed)
{
}

Melee::~Melee()
{
}

void Melee::Parry()
{
}
