#pragma once

#include <BaseComponent.h>
#include <Commands.h>
#include <InputSystem.h>

class AIComponent : public BaseComponent
{
public:
	AIComponent();
	~AIComponent();
	void addFrame(std::vector<Commands::command>);
	void clearQueue();
	std::vector<Commands::command> nextFrame();
	bool queueIsEmpty();
	virtual std::string getComponentType()
	{
		return "AI";
	}
private:
	std::vector<std::vector<Commands::command>> frameQueue;
};