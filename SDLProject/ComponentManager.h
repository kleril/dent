#pragma once

#include <BaseEntity.h>

class ComponentManager
{
public:
	ComponentManager();
	~ComponentManager();
	std::vector<BaseEntity*>getPositionEntities();
	std::vector<BaseEntity*>getTextureEntities();
	std::vector<BaseEntity*>getAIEntities();
	std::vector<BaseEntity*>getSolidEntities();
	void sortTextureEntities();
	void addEntity(BaseEntity* entity);
	void removeEntity(BaseEntity* entity);
private:
	std::vector<BaseEntity*>positionEntities;
	std::vector<BaseEntity*>textureEntities;
	std::vector<BaseEntity*>AIEntities;
	std::vector<BaseEntity*>solidEntities;
};