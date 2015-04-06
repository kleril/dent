#include <PositionComponent.h>


//This might get deleted when it goes out of scope.
PositionComponent::PositionComponent(int x, int y, int xVel, int yVel)
{
	xPos = x;
	yPos = y;
	xVelocity = xVel;
	yVelocity = yVel;
	terminalVelocity = 10;
}

PositionComponent::~PositionComponent()
{
	//Ummmmm... Hi there? There's nothing useful in this destructor, which might be bad.
}

std::pair<int, int> PositionComponent::getPosition()
{
	std::pair <int, int> myPair;
	myPair.first = xPos;
	myPair.second = yPos;
	return myPair;
}

void PositionComponent::setPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}

std::pair<int, int> PositionComponent::getVelocity()
{
	std::pair <int, int> myPair;
	myPair.first = xVelocity;
	myPair.second = yVelocity;
	return myPair;
}

void PositionComponent::setVelocity(int x, int y)
{
	if (x > terminalVelocity)
	{
		x = terminalVelocity;
	}
	if (x < -terminalVelocity)
	{
		x = -terminalVelocity;
	}

	if (y > terminalVelocity)
	{
		y = terminalVelocity;
	}
	if (y < -terminalVelocity)
	{
		y = -terminalVelocity;
	}
	xVelocity = x;
	yVelocity = y;
}