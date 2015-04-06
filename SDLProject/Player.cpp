#include <Player.h>

Player::Player(SDL_Renderer* renderer)
{
	//load shit here
	setTexture("assets/player.png", renderer);
	velX = 0;
	velY = 0;
	maxVel = 5;
}

Player::~Player()
{
	
}

void Player::move()
{
	Player::setPosition(Player::getXPos() + Player::velX, Player::getYPos() + Player::velY);
}

void Player::moveRight()
{
	if (Player::velX < maxVel)
	{
		Player::velX += 1;
	}
}

void Player::moveLeft()
{
	if (Player::velX > -maxVel)
	{
		Player::velX -= 1;
	}
}

void Player::moveUp()
{
	if (Player::velY > -maxVel)
	{
		Player::velY -= 1;
	}
}

void Player::moveDown()
{
	if (Player::velY < maxVel)
	{
		Player::velY += 1;
	}
}

void Player::stopMovingRight()
{
	if (Player::velX >= 1)
	{
		Player::velX -= 1;
	}
}

void Player::stopMovingLeft()
{
	if (Player::velX <= -1)
	{
		Player::velX += 1;
	}
}

void Player::stopMovingUp()
{
	if (Player::velY <= -1)
	{
		Player::velY += 1;
	}
}

void Player::stopMovingDown()
{
	if (Player::velY >= 1)
	{
		Player::velY -= 1;
	}
}