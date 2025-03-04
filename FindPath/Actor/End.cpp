#include "End.h"
#include "Engine/Engine.h"

End::End()
	:DrawableActor("e")
{
	position = Vector2(10, 6);
	this->node = new Node(position);
	color = Color::Red;
}

End::~End()
{
	if (node)
	{
		delete node; 
		node = nullptr;
	}
}

void End::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_RBUTTON))
	{
		position = Engine::Get().MousePosition();
		this->node->SetPosition(position);
	}
}
