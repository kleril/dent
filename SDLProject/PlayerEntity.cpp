#include <BaseEntity.h>

class PlayerEntity : public BaseEntity{
public:
	PlayerEntity(int xPos, int yPos, SDL_Renderer* renderer){
		position = new PositionComponent(xPos, yPos);
		components.push_back(position);
		texture = new TextureComponent();
		texture->loadTexture("assets/player.png", renderer);
		components.push_back(texture);

		int width = texture->getTexture()->getWidth();
		int height = texture->getTexture()->getHeight();
		size = std::make_pair(width, height);
	}

	~PlayerEntity(){
		position->~PositionComponent();
		texture->~TextureComponent();
	}
};