#pragma once

#include <BaseEntity.h>
#include <ComponentManager.h>

class EntityManager {
public:
	EntityManager();
	~EntityManager();
	void addEntity(BaseEntity* entity);
	bool removeEntity(BaseEntity* entity);
	std::vector<BaseEntity*> getEntities();
	ComponentManager* getComponents();
	bool positionOccupied(int x, int y);
private:
	std::vector<BaseEntity*> entities;
	ComponentManager* cm;
};