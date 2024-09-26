#include "Armor.h"

Armor::Armor(std::string name, Texture2D image, std::string description, float weight, float price, int amount, float defense, ClassType armorType) : Item(name, image, description, weight, price, amount)
{
	mClass = armorType;
	mDefense = defense;
}

Armor::~Armor()
{
}
