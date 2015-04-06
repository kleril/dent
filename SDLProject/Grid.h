#pragma once

#include <Controller.h>
#include <vector>

class Grid : public Controller
{
public:
	Grid();
	~Grid();
protected:

private:
	//May need to change this to a tuple (for holding multiple things at 1 position).
	std::vector<std::pair<int, int>>gridPosition;
	int gridPositionX;
	int gridPositionY;
};