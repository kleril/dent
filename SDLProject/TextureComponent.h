#pragma once

#include <BaseComponent.h>
#include <Texture.h>

class TextureComponent : public BaseComponent
{
public:
	TextureComponent();
	~TextureComponent();
	Texture* getTexture();
	bool loadTexture(std::string path, SDL_Renderer* renderer);
	virtual std::string getComponentType()
	{
		return "Texture";
	}
private:
	Texture* mTexture;
	bool animated;
};