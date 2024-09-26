#include "Consumable.h"

Consumable::Consumable(std::string name, Texture2D image, std::string description, float weight, float price, int amount, EffectType effect) : Item(name, image, description, weight, price, amount)
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
