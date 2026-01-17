#include "CollisionSystem.h"
#include <iostream>

void CollisionSystem::Update(std::vector<Object*>& objects)
{
    const size_t size = objects.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			if ((objects[i]->GetType() == ObjectType::BULLET && objects[j]->GetType() == ObjectType::BULLET)
				|| (objects[i]->GetType() == ObjectType::ENEMY && objects[j]->GetType() == ObjectType::ENEMY)
				|| (objects[i]->GetType() == ObjectType::PLAYER && objects[j]->GetType() == ObjectType::BULLET)
				|| (objects[i]->GetType() == ObjectType::BULLET && objects[j]->GetType() == ObjectType::PLAYER))
				continue;

			if (objects[i]->GetRigidBody()->CheckCollision(objects[j]->GetRigidBody()))
			{
					std::cout << "COLLISION\n";
					objects[i]->OnCollision(objects[j]);
					objects[j]->OnCollision(objects[i]);
			}
		}
	}

	for (int i = objects.size() - 1; i >= 0; i--)
	{
		if (objects[i]->IsPendingDestroy())
		{
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}
}
