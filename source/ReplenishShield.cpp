#include "ReplenishShield.h"

void ReplenisherShield::Update()
{
}

bool ReplenisherShield::CollideWithPlayer()
{
}

bool ReplenisherShield::CollideWithBullet()
{
}

void ReplenisherShield::Change()
{
}

void ReplenisherShield::Effect(Player* player)
{
	player->shield = SHIELDMAX;
}
