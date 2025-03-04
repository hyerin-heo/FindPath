#pragma once

#include "Actor/DrawableActor.h"
#include "Algorithm/Node.h"

class End : public DrawableActor
{
	RTTI_DECLARATIONS(End, DrawableActor)
public:
	End();
	~End();

	virtual void Update(float deltaTime) override;
	Node* GetNode() { return node; }
private:
	Node* node = nullptr;
};