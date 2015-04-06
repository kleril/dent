#include <BaseEntity.h>

class WallEntity : public BaseEntity
{
public:
	WallEntity(int xPos, int yPos, SDL_Renderer* renderer)
	{
		position = new PositionComponent(xPos, yPos);
		components.push_back(position);
		texture = new TextureComponent();
		texture->loadTexture("assets/player.png", renderer);
		components.push_back(texture);

		isSolid = true;
		int width = texture->getTexture()->getWidth();
		int height = texture->getTexture()->getHeight();
		size = std::make_pair(width, height);
	}

	~WallEntity()
	{
		position->~PositionComponent();
		texture->~TextureComponent();
	}
};