#include "IncreaseValocity.h"

void IncreaseVelocity::Update()
{
	IncreaseVelocity::Effect();
	Object::Update();
}

bool IncreaseVelocity::CollideWithPlayer()
{
	return true;
}

void IncreaseVelocity::Change()
{
}

void IncreaseVelocity::Effect()
{
	if (hasBeenPlayed == false)
	{
		*playerVelocity += VELOCITY;
		hasBeenPlayed == true;
	}
}
