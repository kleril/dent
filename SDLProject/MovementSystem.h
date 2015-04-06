#pragma once

#include <ComponentManager.h>
#include <EntityManager.h>

class MovementSystem
{
public:
	MovementSystem();
	~MovementSystem();

	void update(ComponentManager* cm, EntityManager* em);
	bool MovementSystem::tryMoving(std::pair<int, int> position, std::pair<int, int> velocity, BaseEntity* entity, EntityManager* em);
private:

};