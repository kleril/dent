#include <BaseEntity.h>
#include <PositionComponent.h>
#include <TextureComponent.h>

class AITestEntity : public BaseEntity{
public:
	AITestEntity(int xPos, int yPos, SDL_Renderer* renderer){
		position = new PositionComponent(xPos, yPos);
		components.push_back(position);
		texture = new TextureComponent();
		texture->loadTexture("assets/player.png", renderer);
		components.push_back(texture);
		AI = new AIComponent();
		components.push_back(AI);
	}

	~AITestEntity(){
		position->~PositionComponent();
		texture->~TextureComponent();
		AI->~AIComponent();
	}
};