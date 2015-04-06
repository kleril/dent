#include <AISystem.h>

AISystem::AISystem()
{

}

AISystem::~AISystem()
{

}

void AISystem::update(BaseEntity* entity, ComponentManager* cm)
{
	AIComponent* AI = entity->getAIComponent();
	std::vector<Commands::command> frameCommands;
	//Determine what action to perform here
	AI->addFrame(frameCommands);
}