#pragma once 
#include "RigidBody.h"
#include "Object.h"

class CollisionSystem {
public:
	void Update(std::vector<Object*>& objects);
};