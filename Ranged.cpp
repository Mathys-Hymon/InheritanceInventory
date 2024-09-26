#include "Ranged.h"

Ranged::Ranged(std::string name, Texture2D image, std::string description, float weight, float price, int amount, float ammo) : Weapon(name, image, description, weight, price, amount)
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
