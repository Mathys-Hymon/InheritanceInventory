#pragma once
#include "Item.h"
#include "ArmorType.h"
#include "IEquippable.h"

class Armor :
    public Item, public IEquippable
{
public:
    Armor(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, float defense, ClassType armorType);
    ~Armor();
    void Equip();

protected:
    float mDefense;
    ClassType mClass;
};

