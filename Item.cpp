#include "Item.h"

Item::Item()
{
}

Item::Item(std::string name, Texture2D image, std::string description, float weight, float price, int amount)
{
    ResetPosition();
    mSize = { (float)image.width, (float)image.height };
    mImage = image;
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
    DrawTextureEx(mImage, mPosition, 0, 1, WHITE);
}

void Item::ResetPosition()
{
    mPosition.x = GetRandomValue(50, GetScreenWidth() - 50);
    mPosition.y = -50;
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
