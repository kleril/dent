#include <CommandSystem.h>


CommandSystem::CommandSystem()
{

}

CommandSystem::~CommandSystem()
{

}

void CommandSystem::doFrameCommands(BaseEntity* entity, ComponentManager* cm)
{
	std::vector<Commands::command> frameCommands = entity->getAIComponent()->nextFrame();
	doFrameCommands(entity, cm, frameCommands);
}

//Framewise calculations should be done here. e.g. velocity easing
void CommandSystem::doFrameCommands(BaseEntity* entity, ComponentManager* cm, std::vector<Commands::command> commands)
{
	moveHor = false;
	moveVert = false;
	for (int i = 0; i < commands.size(); i++)
	{
		doNextCommand(entity, cm, commands.at(i));
	}

	if (!moveHor || !moveVert)
	{
		std::pair<int, int> currentVelocity = entity->getPositionComponent()->getVelocity();
		std::pair<int, int> newVelocity = currentVelocity;
		if (!moveHor && newVelocity.first != 0)
		{
			newVelocity.first += newVelocity.first > 0 ? -1 : 1;
		}
		if (!moveVert && newVelocity.second != 0)
		{
			newVelocity.second += newVelocity.second > 0 ? -1 : 1;
		}
		entity->getPositionComponent()->setVelocity(newVelocity.first, newVelocity.second);
	}
}

void CommandSystem::doNextCommand(BaseEntity* entity, ComponentManager* cm, Commands::command command)
{
	if (entity->getPositionComponent() != NULL)
	{
		std::pair<int, int> currentVelocity = entity->getPositionComponent()->getVelocity();
		std::pair<int, int> newVelocity = currentVelocity;
		if (command == Commands::command::down)
		{
			newVelocity.second++;
			moveVert = true;
		}
		else if (command == Commands::command::right)
		{
			newVelocity.first++;
			moveHor = true;
		}
		else if (command == Commands::command::up)
		{
			newVelocity.second--;
			moveVert = true;
		}
		else if (command == Commands::command::left)
		{
			newVelocity.first--;
			moveHor = true;
		}
		entity->getPositionComponent()->setVelocity(newVelocity.first, newVelocity.second);
	}
}