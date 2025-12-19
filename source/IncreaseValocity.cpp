#include "IncreaseValocity.h"

void IncreaseVelocity::Update()
{

	if (CollideWithBullet)
	{
		PowerUp::
	}

}

bool IncreaseVelocity::CollideWithPlayer()
{

}

bool IncreaseVelocity::CollideWithBullet()
{
}

void IncreaseVelocity::Change()
{
}

void IncreaseVelocity::Effect(Player* player)
{
	player->velocity += VELOCITY;
}
