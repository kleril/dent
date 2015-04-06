#include <AIComponent.h>

AIComponent::AIComponent()
{
	printf("AI Component created");
}
AIComponent::~AIComponent()
{
	frameQueue.clear();
}

void AIComponent::addFrame(std::vector<Commands::command> frame)
{
	frameQueue.push_back(frame);
}

std::vector<Commands::command> AIComponent::nextFrame()
{
	if (frameQueue.size() > 0)
	{
		std::vector<Commands::command> frame = frameQueue.at(frameQueue.size() - 1);
		frameQueue.pop_back();
		return frame;
	}
	else
	{
		std::vector<Commands::command> frame;
		return frame;
	}
}

void AIComponent::clearQueue()
{
	frameQueue.clear();
}

bool AIComponent::queueIsEmpty()
{
	if (frameQueue.size() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}