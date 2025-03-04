#pragma once

#include "Level/Level.h"
#include "Math/Vector2.h"
#include "Algorithm/AStar.h"
#include <vector>
#include <string>

using namespace std;

class Player;
class Start;
class End;
class Node;
class DemoLevel : public Level
{
	// RTTI Á¤ÀÇ.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel(const string& mapName = "Stage1");
	~DemoLevel();

	void LoadMap(const string& mapName);
	void FindPath();

	void SetPoint();

	inline Vector2 MapSize() const { 
		if (maps.empty())
		{
			return Vector2(0, 0);
		}
		return Vector2(maps[0].size()+1, maps.size()+1);
	}


	virtual void Update(float deltaTime);
	virtual void Draw();

private:

	vector<vector<char>> maps;
	Start* start = nullptr;
	End* end = nullptr;
	Player* player = nullptr;
	AStar* aStar = nullptr;

	Vector2 startPosition;

	vector<Node*> nodeList;

	int index = 0;
};