#include <EntityManager.h>

EntityManager::EntityManager()
{
	cm = new ComponentManager();
}
EntityManager::~EntityManager()
{
	for (BaseEntity* entity : entities)
	{
		entity->~BaseEntity();
	}
	entities.clear();
}

void EntityManager::addEntity(BaseEntity* entity)
{
	cm->addEntity(entity);
	entities.push_back(entity);
}

bool EntityManager::removeEntity(BaseEntity* entity)
{
	try
	{
		cm->removeEntity(entity);
		entities.erase(std::find(entities.begin(), entities.end(), entity));
		return true;
	}
	catch (_exception)
	{
		return false;
	}
}

std::vector<BaseEntity*> EntityManager::getEntities()
{
	return entities;
}

ComponentManager* EntityManager::getComponents()
{
	return cm;
}

bool EntityManager::positionOccupied(int x, int y)
{
	bool isOccupied = false;
	for (int i = 0; i < cm->getSolidEntities().size(); i++)
	{
		if (cm->getSolidEntities().at(i)->positionOccupied(x, y))
		{
			isOccupied = true;
			return isOccupied;
		}
	}
	return isOccupied;
}