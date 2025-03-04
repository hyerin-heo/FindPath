#pragma once

#include "Actor/DrawableActor.h"
#include "Algorithm/Node.h"

class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)

public:
	Player();
	~Player();

	virtual void Update(float deltaTime) override;
	Node* GetNode() { return node; }
private:
	Node* node = nullptr;
};