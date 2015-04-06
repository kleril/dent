#pragma once

#include <BaseEntity.h>
#include <ComponentManager.h>

class CommandSystem
{
public:
	CommandSystem();
	~CommandSystem();
	void doFrameCommands(BaseEntity* entity, ComponentManager* cm);
	void doFrameCommands(BaseEntity* entity, ComponentManager* cm, std::vector<Commands::command> command);
	void doNextCommand(BaseEntity* entity, ComponentManager* cm, Commands::command);

private:
	bool moveHor = false, moveVert = false;
};