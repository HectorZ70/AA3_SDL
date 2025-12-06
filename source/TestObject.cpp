#include "TestObject.h"
#include <iostream>


void Player::Update()
{
		bool hasMoved = false;
		if (IM->GetEvent(SDLK_S, HOLD))
			{
			_transform->position = { _transform->position.x ,_transform->position.y + 5.f };
			}
		if (IM->GetEvent(SDLK_W, HOLD))
		{
			_transform->position = { _transform->position.x ,_transform->position.y - 5.f };
		}
		if (IM->GetEvent(SDLK_A, HOLD))
		{
			_transform->position = { _transform->position.x - 5.f  ,_transform->position.y};
		}
		if (IM->GetEvent(SDLK_D, HOLD))
		{
			_transform->position = { _transform->position.x + 5.f  ,_transform->position.y};
		}


		

		std::cout << _transform->position.x << " " << _transform->position.y << "\n";

		Object::Update();

}

void Player::Render()
{
	_renderer->Render();
}
