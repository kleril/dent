#include <Renderable.h>

/*
public:
Renderable();
~Renderable();
std::pair<int,int> getPosition();
int getXPos();
int getYPos();
void setPosition(int xPos, int yPos);
Texture getTexture();
void setTexture();
bool load();
bool unload();
private:
Texture mTexture;
int xPos;
int yPos;
*/

Renderable::Renderable()
{
	//Init code here
	Texture* mTexture = new Texture();
}

Renderable::~Renderable()
{
	//Uncomment this if memory leaks
	//delete &mTexture;
	//Destructor code here
}

std::pair<int, int> Renderable::getPosition()
{
	return std::make_pair(xPos, yPos);
}

int Renderable::getXPos()
{
	return xPos;
}

int Renderable::getYPos()
{
	return yPos;
}

Texture Renderable::getTexture()
{
	return mTexture;
}

void Renderable::setPosition(int newXPos, int newYPos)
{
	xPos = newXPos;
	yPos = newYPos;
}

void Renderable::setTexture(std::string fileName, SDL_Renderer* renderer)
{
	//Find a way to pass the global renderer to this...
	mTexture.loadFromFile(fileName, renderer);
}