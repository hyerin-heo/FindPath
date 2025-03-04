#include "Player.h"
#include "Engine/Engine.h"

Player::Player()
	: DrawableActor("p")
{
	color = Color::Green;
	position = Vector2(5, 5);
	node = new Node(position);
}

Player::~Player()
{
	SafeDelete(node);
}

void Player::Update(float deltaTime)
{
	DrawableActor::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
}