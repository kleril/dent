#include <Input.h>
#include <Commands.h>
#include <vector>

//Entities
#include <PlayerEntity.cpp>
#include <WallEntity.cpp>
#include <AITestEntity.cpp>

//Managers
#include <EntityManager.h>
#include <LoadingManager.h>

//Systems
#include <InputSystem.h>
#include <MovementSystem.h>
#include <AISystem.h>
#include <CommandSystem.h>

class Game {
public:
	Game(SDL_Renderer* renderer);
	~Game();
	void simulate(float numTicks, Input inputPass);
	void processInput(Input inputPass);
	void render(SDL_Renderer* renderer);
	void doPlayerCommands();
protected:

private:
	PlayerEntity* ePlayer;
	AITestEntity* eAITest;
	WallEntity* eWall;
	EntityManager* em;
	InputSystem* input;
	std::vector<Commands::command> commands;
	MovementSystem* moveSystem;
	AISystem* AISys;
	CommandSystem* commandSys;
	LoadingManager* lm;
};