#include <ComponentManager.h>

//Maaaaybe separate this into its own header file.


ComponentManager::ComponentManager()
{
	//Uhhh... Do I need to instantiate vectors? If so, do it here.
}

ComponentManager::~ComponentManager()
{
	positionEntities.clear();
	textureEntities.clear();
}

void ComponentManager::addEntity(BaseEntity* entity)
{
	std::vector<BaseComponent*> components = entity->getComponents();
	for (BaseComponent* component : components)
	{
		if (component->getComponentType().compare("Position") == 0)
		{
			positionEntities.push_back(entity);
		}
		else if (component->getComponentType().compare("Texture") == 0)
		{
			textureEntities.push_back(entity);
		}
		else if (component->getComponentType().compare("AI") == 0)
		{
			AIEntities.push_back(entity);
		}
	}
	if (entity->getSolidity())
	{
		solidEntities.push_back(entity);
	}
}

//This is horribly inefficient and probably doesn't work
void ComponentManager::removeEntity(BaseEntity* entity)
{
	positionEntities.erase(std::find(positionEntities.begin(), positionEntities.end(), entity));
	textureEntities.erase(std::find(textureEntities.begin(), textureEntities.end(), entity));
	AIEntities.erase(std::find(AIEntities.begin(), AIEntities.end(), entity));
	solidEntities.erase(std::find(solidEntities.begin(), solidEntities.end(), entity));
}

//Sorts Texture Entities by y-position - ascending
void ComponentManager::sortTextureEntities()
{
	//TODO: Finish entity sort by position.
	printf("Texture entity sort isn't done yet. Stop using it.");
}

std::vector<BaseEntity*> ComponentManager::getPositionEntities()
{
	return positionEntities;
}

std::vector<BaseEntity*> ComponentManager::getTextureEntities()
{
	return textureEntities;
}

std::vector<BaseEntity*> ComponentManager::getAIEntities()
{
	return AIEntities;
}

std::vector<BaseEntity*> ComponentManager::getSolidEntities()
{
	return solidEntities;
}