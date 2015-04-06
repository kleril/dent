#pragma once

#include <Map.h>
#include <Player.h>

class TestMap : public Map
{
public:
	TestMap();
	~TestMap();
	//Gets location on the grid
	std::pair<int, int> getGridPosition(GameObject entity);
	//Gets raw coordinates
	std::pair<int, int> getRawPosition(GameObject entity);
protected:

private:
	Grid mapGrid;
	Player* playerInst;
};