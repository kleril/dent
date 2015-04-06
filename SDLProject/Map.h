#pragma once

#include <Controller.h>
#include <Grid.h>
#include <Renderable.h>

class Map : public Controller {
public:
	Map();
	~Map();
	//Gets location on the grid
	std::pair<int, int> getGridPosition(Renderable entity);
	//Gets raw coordinates
	std::pair<int, int> getRawPosition(Renderable entity);
	bool load(std::string fileName);
	bool unload();
protected:

private:
	//Grid mapGrid;
};