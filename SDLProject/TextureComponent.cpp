#include <TextureComponent.h>

TextureComponent::TextureComponent()
{
	mTexture = new Texture();
}

TextureComponent::~TextureComponent()
{
	mTexture->free();
}

bool TextureComponent::loadTexture(std::string path, SDL_Renderer* renderer)
{
	if (mTexture->loadFromFile(path, renderer))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Texture* TextureComponent::getTexture()
{
	return mTexture;
}