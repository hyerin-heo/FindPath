#pragma once

#include "Actor/DrawableActor.h"
#include "Algorithm/Node.h"

class Start : public DrawableActor
{
public:
	Start();

	virtual void Update(float deltaTime) override;
	Node* GetNode() { return node; }
private:
	Node* node = nullptr;
};