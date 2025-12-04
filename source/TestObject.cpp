#include "TestObject.h"



void Player::Update()
{

		bool hasMoved = false;
		Vector2 vel = { 0, 0 };
		if (IM->GetEvent(SDLK_S, HOLD))
		{
			vel.y = 100.f;
			hasMoved = true;
		}

		if (IM->GetEvent(SDLK_W, HOLD))
		{
			vel.y = -100.f;
			hasMoved = true;

		}

		if (IM->GetEvent(SDLK_A, HOLD))
		{
			vel.x = -100.f;
			hasMoved = true;

		}

		if (IM->GetEvent(SDLK_D, HOLD))
		{
			vel.x = 100.f;
			hasMoved = true;

		}

		

		std::cout << _transform->position.x << " " << _transform->position.y << "\n";


		Object::Update();

}

void Player::Render()
{
	_renderer->Render();
}
