#include "DemoLevel.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Space.h"
#include "Actor/Player.h"
#include "Actor/Start.h"
#include "Actor/End.h"
#include "Algorithm/Node.h"
#include "Engine/Timer.h"
#include "Engine/Engine.h"
#include <Windows.h>

DemoLevel::DemoLevel(const string& mapName)
{
	aStar = new AStar();
	LoadMap(mapName);
}

DemoLevel::~DemoLevel()
{
	if (aStar)
	{
		delete aStar;
		aStar = nullptr;
	}
}

void DemoLevel::LoadMap(const string& mapName)
{
	FILE* file = nullptr;
	string path = "../Assets/Maps/" + mapName + ".txt";
	fopen_s(&file, path.c_str(), "rb");
	if (file == nullptr)
	{
		std::cout << "fail to open map file!\n";
		__debugbreak();
		return;
	}

	//move file's end point
	fseek(file, 0, SEEK_END);

	size_t fileSize = ftell(file);

	//move file's start point
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	char* buffer = new char[fileSize + 1];// add 1 => '\0'

	// fread => ????
	size_t readBytes = fread(buffer, 1, fileSize, file);

	if (readBytes != fileSize)
	{
		std::cout << "diffrent size between read and file\n";
		__debugbreak();
		return;
	}
	buffer[fileSize] = '\0';

	int index = 0;

	int xPosition = 0;
	int yPosition = 0;

	vector<char> map;

	// parsing
	while (index < (int)readBytes)
	{
		char mapChar = buffer[index++];

		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			maps.emplace_back(map);
			map.clear();
			continue;
		}
		else if (mapChar == '1')
		{
			AddActor(new Wall(Vector2(xPosition, yPosition)));
			map.emplace_back('1');
		}
		else if (mapChar == '.')
		{
			AddActor(new Ground(Vector2(xPosition, yPosition)));
			map.emplace_back(' ');
		}
		else {
			AddActor(new Space(Vector2(xPosition, yPosition)));
			map.emplace_back('1');
		}

		++xPosition;
	}

	delete[] buffer;

	fclose(file);
}

void DemoLevel::FindPath()
{
	nodeList.clear();
	index = 0;
	startPosition = start->Position();
	nodeList = aStar->FindPath(start->GetNode(), end->GetNode(), maps);
}

void DemoLevel::SetPoint()
{
	start = new Start();
	end = new End();
	player = new Player();
	AddActor(start);
	AddActor(end);
	AddActor(player);
}

void DemoLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);


	if (startPosition != start->Position())
	{
		FindPath();
	}

	static Timer timer(0.2f);
	timer.Update(deltaTime);
	if (timer.IsTimeOut())
	{
		timer.Reset();
		if (!nodeList.empty())
		{
			if (nodeList.size() > index)
			{
				player->SetPosition(nodeList[index]->Position());
				++index;
			}
		}
	}
}

void DemoLevel::Draw()
{
	Super::Draw();
}
