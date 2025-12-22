#include "ReplenishingEnergyCannon.h"

void ReplenisherEnergyCannon::Update()
{
	ReplenisherEnergyCannon::Effect();
	Object::Update();
}

bool ReplenisherEnergyCannon::CollideWithPlayer()
{
	return true;
}

void ReplenisherEnergyCannon::Change()
{
}

void ReplenisherEnergyCannon::Effect()
{
	*cannonAmmunation += MAX;
}
