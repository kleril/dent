#include <Map.h>
/*
Map();
~Map();

private:
Grid mapGrid;
*/

const int GRID_SIZE = 16;

Map::Map()
{

}

Map::~Map()
{

}

//Gets location on the grid
std::pair<int, int> Map::getGridPosition(Renderable entity)
{
	std::pair<int, int> rawPos = getRawPosition(entity);
	std::pair<int, int> gridPos = std::make_pair (rawPos.first / GRID_SIZE, rawPos.second / GRID_SIZE);
	return gridPos;
}

//Gets raw coordinates
std::pair<int, int> Map::getRawPosition(Renderable entity)
{
	return entity.getPosition();
}

bool Map::load(std::string fileName)
{
	return true;
}

bool Map::unload()
{
	return true;
}