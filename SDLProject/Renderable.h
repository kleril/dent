#pragma once

#include <SDL.h>
#include <GameObject.h>
#include <Texture.h>

class Renderable : public GameObject{
public:
	Renderable();
	~Renderable();
	std::pair<int,int> getPosition();
	int getXPos();
	int getYPos();
	void setPosition(int xPos, int yPos);
	Texture getTexture();
	void setTexture(std::string fileName, SDL_Renderer* renderer);
private:
	Texture mTexture;
	int xPos;
	int yPos;
};