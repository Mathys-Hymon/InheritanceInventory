#pragma once
#include "PotionEffect.h"

class Consumable
{
public:
	void Use();
protected:
	EffectType mEffect;
};

