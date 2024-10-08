#pragma once
#include "PotionEffect.h"
#include "IStackable.h"
#include "Item.h"

class Consumable : 
	public Item, public IStackable
{
public:
	Consumable();
	Consumable(std::string name, Texture2D image, std::string description, float weight, float price, int amount, ItemTag tag, EffectType effect);
	~Consumable();
	void Add(int amount);
	void Use();
protected:
	EffectType mEffect;
};

