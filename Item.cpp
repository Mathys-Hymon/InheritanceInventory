#include "Item.h"

Item::Item()
{
}

Item::Item(std::string name, Texture2D image, std::string description, float weight, float price, int amount)
{
}

Item::~Item()
{
}

void Item::Drop(int quantity)
{
}

void Item::Inspect()
{
}

void Item::Sell()
{
}

void Item::Favorite()
{
}

std::string Item::GetName()
{
    return std::string();
}

std::string Item::GetDesc()
{
    return std::string();
}

int Item::GetPrice()
{
    return 0;
}

ItemTag Item::GetTag()
{
    return ItemTag();
}

Texture2D* Item::GetImage()
{
    return &mImage;
}

int Item::GetAmount()
{
    return mAmount;
}
