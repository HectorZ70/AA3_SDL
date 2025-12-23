#include "ReplenishShield.h"

void ReplenisherShield::Update()
{
	ReplenisherShield::Effect();
	Object::Update();
}

bool ReplenisherShield::CollideWithPlayer()
{
	return true;
}

void ReplenisherShield::Change()
{
}

void ReplenisherShield::Effect()
{
	if (hasBeenPlayed == false)
	{
		*shield += MAX;
		hasBeenPlayed = true;
	}

}
