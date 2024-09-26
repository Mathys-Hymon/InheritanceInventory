#include "Consumable.h"

Consumable::Consumable() : Item()
{
}

Consumable::Consumable(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, EffectType effect) : Item(name, image, description, weight, price, amount, tag)
{
	mEffect = effect;
}

Consumable::~Consumable()
{
}

void Consumable::Add(int amount)
{

}

void Consumable::Use()
{
}
