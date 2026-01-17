#pragma once
#include "Enemy.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void Enemy::OnCollision(Object* other) 
{
	if (other->GetType() == ObjectType::BULLET)
		Destroy();
}
