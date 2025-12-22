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
	*shield += MAX;

}
