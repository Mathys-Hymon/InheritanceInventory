#include "Ranged.h"

Ranged::Ranged() : Weapon()
{
}

Ranged::Ranged(std::string name, Texture2D image, std::string description, float weight, float price, int amount, float damages, ItemTag tag, float attackSpeed, float ammo) : Weapon(name, image, description, weight, price, amount,tag, damages, attackSpeed)
{
	mAmmo = ammo;
}

Ranged::~Ranged()
{
}

void Ranged::Aim()
{
}

void Ranged::Reload()
{
}
