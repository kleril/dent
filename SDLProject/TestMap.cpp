#include <TestMap.h>

TestMap::TestMap()
{
	Player* playerInst = new Player();
	playerInst->load();
	playerInst->setPosition(1,1);
}

TestMap::~TestMap()
{
	delete playerInst;
	//Unload shit from the map!
}

bool load()
{
	return true;
}

bool unload()
{
	return true;
}