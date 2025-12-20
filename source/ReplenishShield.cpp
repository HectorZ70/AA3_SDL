#include "ReplenishShield.h"

void ReplenisherShield::Update()
{
}

bool ReplenisherShield::CollideWithPlayer()
{
	return true;
}

void ReplenisherShield::Change()
{
}

void ReplenisherShield::Effect(Player* player)
{
	player->shield = SHIELDMAX;
}
