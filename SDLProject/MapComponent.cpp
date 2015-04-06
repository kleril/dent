#include <MapComponent.h>

MapComponent::MapComponent()
{

}

MapComponent::~MapComponent()
{
	unloadMap();
}

std::string getComponentType()
{
	return "MapComponent";
}

//Change entity's type to a better identifier... Int could cause problems
bool MapComponent::addEntity(std::pair<int, int> position, int entity)
{
	bool loadSucceed = false;
	try
	{

	}
	catch (...)
	{
		printf("Could not load entity onto map!");
		printf("Position: %i , %i", position.first, position.second);
		printf("Entity: %i", entity);
	}
	return loadSucceed;
}

bool MapComponent::moveEntity(std::pair<int, int> newPosition, std::vector<int> entities)
{
	bool moveSucceed = false;

	return moveSucceed;
}

//Fix this if map unloading breaks somehow.
bool MapComponent::unloadMap()
{
	entityAtPosition.clear();
	return true;
}