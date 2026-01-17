#pragma once
#include "Object.h"
#include "TextRenderer.h"

class TextObject : public Object
{
public:
	TextObject(std::string text, float xPos, float yPos) : Object()
		{
		_renderer = new TextRenderer(_transform, text);
		_renderer->SetColor({ 255 , 255 , 255, 0xFF });
		_transform->position = { xPos, yPos };
		_transform->rotation = { 0.f };
		}
		void SetText(std::string text)
		{
		dynamic_cast <TextRenderer*>(_renderer)->SetText(text);
		}
};