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
	*laserAmmunation += MAX;
}
