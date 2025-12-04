#include "Button.h"

void Button::OnHoverEnter()
{
	_transform->rotation = 90.f;
	_isHovered = true;
}

void Button::OnHoverExit()
{
	_transform->rotation = 0.f;
	_isHovered = false;
}

void Button::OnClicked()
{
	_onClick();
}
