#pragma once

#include <BaseComponent.h>
#include <PositionComponent.h>
#include <TextureComponent.h>
#include <AIComponent.h>
#include <vector>

class BaseEntity{
public:
	BaseEntity();
	~BaseEntity();
	bool getSolidity();
	bool positionOccupied(int x, int y);
	std::pair<int, int>getSize();
	std::vector<BaseComponent*> getComponents();
	Texture* getTexture();
	PositionComponent* getPositionComponent();
	AIComponent* getAIComponent();
protected:
	bool isSolid = false;
	std::pair<int, int> size = std::make_pair(1,1);
	//BIG ASS LIST OF COMPONENTS. SHIT GON BE SCARY.
	PositionComponent* position = NULL;
	TextureComponent* texture = NULL;
	AIComponent* AI = NULL;
	std::vector<BaseComponent*> components;
};