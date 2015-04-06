#include <Renderable.h>

class Player : public Renderable
{
public:
	Player(SDL_Renderer* renderer);
	~Player();
	void move();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void stopMovingUp();
	void stopMovingDown();
	void stopMovingLeft();
	void stopMovingRight();
	void warpTo(int x, int y);
protected:

private:
	int velX;
	int velY;
	int maxVel;
};