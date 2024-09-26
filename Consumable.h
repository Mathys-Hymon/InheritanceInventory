#pragma once
#include "PotionEffect.h"
#include "IStackable.h"

class Consumable : 
	public Item, public IStackable
{
public:
	Consumable();
	~Consumable();
	void Add(int amount);
	void Use();
protected:
	EffectType mEffect;
};

