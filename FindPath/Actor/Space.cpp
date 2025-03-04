#include "Space.h"

Space::Space(const Vector2& position)
	:DrawableActor(".")
{
	this->position = position;

	color = Color::White;
}

Space::~Space()
{
}
