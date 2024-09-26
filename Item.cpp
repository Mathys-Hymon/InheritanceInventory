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
    ResetPosition();
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

void Item::Update()
{
    mPosition.y += 100 * GetFrameTime();
    if (mPosition.y > GetScreenHeight() + 50)
    {
        ResetPosition();
    }
    if (CheckCollisionPointRec(GetMousePosition(), { mPosition.x, mPosition.y, mSize.x, mSize.y })) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            mIsClicked = true;
            ResetPosition();
        }
    }
}

void Item::Draw()
{
    DrawTexture(mImage, 500, 500, WHITE);
}

void Item::ResetPosition()
{
    mPosition.x = GetRandomValue(50, GetScreenWidth() - 50);
    mPosition.y = 50;
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

bool Item::GetIsClicked()
{
    return mIsClicked;
}

void Item::SetIsClicked(bool state)
{
    mIsClicked = state;
}
