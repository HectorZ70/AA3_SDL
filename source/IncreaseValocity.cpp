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
	*playerVelocity += VELOCITY;
}
