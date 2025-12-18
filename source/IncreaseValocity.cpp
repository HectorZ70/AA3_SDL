#include "IncreaseValocity.h"

void IncreaseVelocity::Update()
{
}

void IncreaseVelocity::CollideWithPlayer()
{
}

void IncreaseVelocity::CollideWithBullet()
{
}

void IncreaseVelocity::Change()
{
}

void IncreaseVelocity::Effect(Player* player)
{
	player->velocity += VELOCITY;
}
