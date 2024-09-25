#pragma once
#include "Item.h"

enum class ClassType
{
    light,
    heavy,
    normal,
};

class Armor :
    public Item
{
protected:
    float mDefense;
    ClassType mClass;
};

