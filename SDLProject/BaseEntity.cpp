#include <BaseEntity.h>

BaseEntity::BaseEntity(){

}

BaseEntity::~BaseEntity(){

}

std::vector<BaseComponent*> BaseEntity::getComponents()
{
	return components;
}

bool BaseEntity::getSolidity()
{
	return isSolid;
}

bool BaseEntity::positionOccupied(int x, int y)
{
	bool isOccupied = false;
	if (position != NULL)
	{
		std::pair<int, int> myPos = position->getPosition();
		if (x > myPos.first && x < myPos.first + size.first)
		{
			if (y > myPos.second && y < myPos.second + size.second)
			{
				isOccupied = true;
			}
		}
	}
	return isOccupied;
}

std::pair<int, int> BaseEntity::getSize()
{
	return size;
}

Texture* BaseEntity::getTexture()
{
	if (texture != NULL)
	{
		return texture->getTexture();
	}
	else return NULL;
}

PositionComponent* BaseEntity::getPositionComponent()
{
	if (position != NULL)
	{
		return position;
	}
	else return NULL;
}

AIComponent* BaseEntity::getAIComponent()
{
	if (AI != NULL)
	{
		return AI;
	}
	else return NULL;
}