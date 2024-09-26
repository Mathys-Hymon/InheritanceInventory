#include "Item.h"

Item::Item()
{
    mSize = {0,0};
    mImage = Texture2D();
    mName = " ";
    mDescription = " ";
    mWeight = 0;
    mPrice = 0;
    mAmount = 0;
    mTag = ItemTag::armor;

    mIsFavorited = false;
}

Item::Item(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag)
{
    mSize = { (float)image.width, (float)image.height};
    mImage = image;
    mName = name;
    mDescription = description;
    mWeight = weight;
    mPrice = price;
    mAmount = amount;
    mTag = tag;

    mIsFavorited = false;
}

Item::~Item()
{
}

void Item::Drop(int quantity)
{
    if (mAmount > 0) {
        mAmount -= 1;
    }
}

void Item::Inspect()
{

}

void Item::Sell()
{
    Drop(1);
}

void Item::Favorite()
{
    mIsFavorited = !mIsFavorited;
}

void Item::Update()
{
}

void Item::Draw()
{
    DrawTexture(mImage, 500, 500, WHITE);
}

void Item::Unload()
{
    UnloadTexture(mImage);
}


std::string Item::GetName()
{
    return mName;
}

std::string Item::GetDesc()
{
    return mDescription;
}

int Item::GetPrice()
{
    return mPrice;
}

ItemTag Item::GetTag()
{
    return mTag;
}

Texture2D* Item::GetImage()
{
    return &mImage;
}

int Item::GetAmount()
{
    return mAmount;
}

bool Item::GetIsFavorited()
{
    return mIsFavorited;
}
