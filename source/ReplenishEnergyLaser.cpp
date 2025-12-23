#include "ReplenishEnergyLaser.h"

void ReplenisherEnergyLaser::Update()
{
	ReplenisherEnergyLaser::Effect();
	Object::Update();
}

bool ReplenisherEnergyLaser::CollideWithPlayer()
{
	return true;
}

void ReplenisherEnergyLaser::Change()
{
}

void ReplenisherEnergyLaser::Effect()
{
	if (hasBeenPlayed == false)
	{
		*laserAmmunation += MAX;
		hasBeenPlayed = true;
	}
}
