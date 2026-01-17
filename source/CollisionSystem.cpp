#include "CollisionSystem.h"

void CollisionSystem::Update(std::vector<Object*>& objects)
{
    const size_t size = objects.size();

    for (size_t i = 0; i < size; i++)
    {
        Object* a = objects[i];
        if (a->IsPendingDestroy()) continue;
        if (!a->GetRigidBody()) continue;

        for (size_t j = i + 1; j < size; j++)
        {
            Object* b = objects[j];
            if (b->IsPendingDestroy()) continue;
            if (!b->GetRigidBody()) continue;

            if (a->GetRigidBody()->CheckCollision(b->GetRigidBody()))
            {
                a->OnCollision(b);
                b->OnCollision(a);
            }
		}
	}
}
