#include "Armor.h"

Armor::Armor(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, float defense, ClassType armorType) : Item(name, image, description, weight, price, amount,tag)
{
	mClass = armorType;
	mDefense = defense;
}

Armor::~Armor()
{
}

void Armor::Equip()
{
}
