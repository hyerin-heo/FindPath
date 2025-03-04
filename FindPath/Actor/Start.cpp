#include "Start.h"
#include "Engine/Engine.h"

Start::Start()
	: DrawableActor("s")
{
	color = Color::Blue;
}

void Start::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_LBUTTON))
	{
		position = Engine::Get().MousePosition();
		this->node = new Node(position);
	}
}