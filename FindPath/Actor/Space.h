#pragma once
#include "Actor/DrawableActor.h"
#include "Math/Vector2.h"

class Space : public DrawableActor {
	RTTI_DECLARATIONS(Space, DrawableActor)
public:
	Space(const Vector2& position);
	~Space();
private:

};