#pragma once
#include "PotionEffect.h"

class Consumable
{
public:
	Consumable();
	~Consumable();
	void Use();
protected:
	EffectType mEffect;
};

