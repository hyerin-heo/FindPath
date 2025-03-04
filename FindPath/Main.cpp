#include "Engine/Engine.h"
#include "Level/DemoLevel.h"

int main()
{
	CheckMemoryLeak();
	DemoLevel* level = new DemoLevel();
	Engine engine(level->MapSize());
	engine.LoadLevel(level);
	level->SetPoint();
	engine.Run();
}