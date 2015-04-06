#pragma once

#include <BaseComponent.h>

class PositionComponent : public BaseComponent
{
public:
	PositionComponent(int xPosition, int yPosition, int xVelocity = 0, int yVelocity = 0);
	~PositionComponent();
	virtual std::string getComponentType()
	{
		return "Position";
	}
	std::pair<int, int> getVelocity();
	std::pair<int, int> getPosition();

	void setVelocity(int x, int y);
	void setPosition(int x, int y);
private:
	int xPos;
	int yPos;
	int xVelocity;
	int yVelocity;
	int terminalVelocity;
};