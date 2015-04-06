#include <MovementSystem.h>
#include <ctime>

MovementSystem::MovementSystem()
{
	srand(static_cast <unsigned> (std::time(0)));
}

MovementSystem::~MovementSystem()
{

}

//Runs through each position entity and attempts to update their position based on current velocity.
void MovementSystem::update(ComponentManager* cm, EntityManager* em)
{
	for (int i = 0; i < cm->getPositionEntities().size(); i++)
	{
		BaseEntity* entity = cm->getPositionEntities().at(i);
		std::pair<int, int> currentPosition = entity->getPositionComponent()->getPosition();
		std::pair<int, int> velocity = entity->getPositionComponent()->getVelocity();
		tryMoving(currentPosition, velocity, entity, em);
	}
}

//TODO: Clean this nonsense up. Make a helper method for speed reduction, and maybe find a cleaner way to iterate over collision areas.
//TODO: Separate the bounce behaviour into it's own method based on entity properties. BouncePropensity (in PositionComponent)

//Checks to see if the position is occupied by a solid object, and bounces if moving there would result in a collision.
bool MovementSystem::tryMoving(std::pair<int, int> position, std::pair<int, int> velocity, BaseEntity* entity, EntityManager* em)
{
	std::pair<int, int> newPosition = position;
	int xPos = position.first;
	int yPos = position.second;
	int xVel = velocity.first;
	int yVel = velocity.second;
	bool xFit = false;
	bool yFit = false;
	//Collision check. Checks each corner of an object to see if the position it's headed to is occupied.
	while (xVel != 0 && xFit == false)
	{
		//Top Left Check
		if (em->positionOccupied(xPos + xVel, yPos))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Bottom Right Check
		else if (em->positionOccupied(xPos + xVel + entity->getSize().first, yPos + entity->getSize().second))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Bottom Middle Check
		else if (em->positionOccupied(xPos + xVel + entity->getSize().first / 2, yPos + entity->getSize().second))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Right Middle Check
		else if (em->positionOccupied(xPos + xVel + entity->getSize().first, yPos + entity->getSize().second/2))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Top Middle Check
		else if (em->positionOccupied(xPos + xVel + entity->getSize().first / 2, yPos))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Left Middle Check
		else if (em->positionOccupied(xPos + xVel, yPos + entity->getSize().second / 2))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Bottom Left Check
		else if (em->positionOccupied(xPos + xVel, yPos + entity->getSize().second))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		//Top Right Check
		else if (em->positionOccupied(xPos + xVel + entity->getSize().first, yPos))
		{
			if (xVel != 0)
			{
				if (xVel == 1 || xVel == -1)
				{
					xVel = 0;
				}
				else
				{
					xVel += xVel > 0 ? -2 : 2;
				}
			}
			xVel = -xVel;
		}
		else
		{
			xFit = true;
		}
	}

	while (yVel != 0 && yFit == false)
	{
		//Top Left Check
		if (em->positionOccupied(xPos, yPos + yVel))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Bottom Right Check
		else if (em->positionOccupied(xPos + entity->getSize().first, yPos + yVel + entity->getSize().second))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Bottom Middle Check
		else if (em->positionOccupied(xPos + entity->getSize().first / 2, yPos + yVel + entity->getSize().second))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Right Middle Check
		else if (em->positionOccupied(xPos + entity->getSize().first, yPos + yVel + entity->getSize().second / 2))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Top Middle Check
		else if (em->positionOccupied(xPos + entity->getSize().first / 2, yPos + yVel))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Left Middle Check
		else if (em->positionOccupied(xPos, yPos + yVel + entity->getSize().second / 2))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Bottom Left Check
		else if (em->positionOccupied(xPos, yPos + yVel + entity->getSize().second))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		//Top Right Check
		else if (em->positionOccupied(xPos + entity->getSize().first, yPos + yVel))
		{
			if (yVel != 0)
			{
				if (yVel == 1 || yVel == -1)
				{
					yVel = 0;
				}
				else
				{
					yVel += yVel > 0 ? -2 : 2;
				}
			}
			yVel = -yVel;
		}
		else
		{
			yFit = true;
		}
	}
	entity->getPositionComponent()->setVelocity(xVel, yVel);
	entity->getPositionComponent()->setPosition(xVel + xPos, yVel + yPos);
	return true;
}