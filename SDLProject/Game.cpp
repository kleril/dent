#include <Game.h>

using namespace Commands;

Game::Game(SDL_Renderer* rendererPass)
{
	//Initialize all systems
	em = new EntityManager();
	lm = new LoadingManager();
	input = new InputSystem();
	moveSystem = new MovementSystem();
	AISys = new AISystem();
	commandSys = new CommandSystem();

	//Try loading map in
	try
	{
		lm->loadMap("assets/testMap2.tmx");
	}
	//Load fail state
	catch (std::exception e)
	{
		
	}
	ePlayer = new PlayerEntity(10, 10, rendererPass);
	em->addEntity(ePlayer);
	eWall = new WallEntity(50, 50, rendererPass);
	em->addEntity(eWall);
}

Game::~Game()
{
	//Close game
}

//TODO: Change command system calls so everything runs off the same whoozit.

//Run through all systems & do things.
void Game::simulate(float numTicks, Input inputPass)
{
	//Get input, convert it to commands
	processInput(inputPass);
	
	//OK SO. Here's a thing. Commands is reusable, so you can throw the same set of input to multiple entities...
	//But to do that, the stuff below this has to be restructured so doFrameCommands runs more than just ePlayer.
	//Probably a good idea to change that anyway 'cause it means you're not relying on a hardcoded entity to do all playing.

	//Do commands for Player
	commandSys->doFrameCommands(ePlayer, em->getComponents(), commands);
	//Update all systems
	//Do commands for all AI.
	if (!em->getComponents()->getAIEntities().empty())
	{
		for (int i = 0; i <= em->getComponents()->getAIEntities().size() - 1; i++)
		{
			BaseEntity* entity = em->getComponents()->getAIEntities().at(i);
			commandSys->doFrameCommands(entity, em->getComponents(), entity->getAIComponent()->nextFrame());
			AISys->update(entity, em->getComponents());
		}
	}
	moveSystem->update(em->getComponents(), em);
}

void Game::processInput(Input inputPass)
{
	input->inputToCommands(inputPass);
	input->updateMousePosition(inputPass);
	commands = input->getCommands();
}

void Game::render(SDL_Renderer* renderer)
{
	//Put things to be rendered in the renderer
	for (int i = 0; i < em->getComponents()->getTextureEntities().size(); i++)
	{
		Texture* entityTexture = em->getComponents()->getTextureEntities().at(i)->getTexture();
		std::pair<int, int> position = em->getComponents()->getTextureEntities().at(i)->getPositionComponent()->getPosition();
		entityTexture->render(renderer, position.first, position.second);
	}
}