#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
//My shit
#include <Window.h>
#include <Input.h>
#include <Timer.h>
#include <Game.h>

//Input polling rate (in ticks)
const int INPUT_POLLING_RATE = 100;

//Init stuff:
Window gWindow;
SDL_Renderer* gRenderer = NULL;
Input inputManager;
Game* gameInstance;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		if (!gWindow.init())
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = gWindow.createRenderer();
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

void closeGame(){
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	gWindow.free();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Fix this.
		//TestMap testMapInst;
		//GameObject * testMapObj = &testMapInst;
		gameInstance = new Game(gRenderer);
		if (!1==1)
		{
			printf("Failed to load main menu!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Timer
			Timer stepTimer;
			float timeStep = 1000;

			//While application is running
			while (quit == false)
			{
				//This is some black magic. The polling rate prevents lag FOR SOME FUCKING REASON BUT DON'T ASK ME HOW
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0 && timeStep > INPUT_POLLING_RATE)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					if (&Window::handleEvent)
					{
						SDL_RenderPresent(gRenderer);
					}
					inputManager.handleInput(e);
				}
				//Game logic goes here
				//Calculate time step
				timeStep = stepTimer.getTicks() / 1000.f;
				//Move for time step
				gameInstance->simulate(timeStep, inputManager);
				//Restart step timer
				stepTimer.start();

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Update render
				gameInstance->render(gRenderer);


				//Refresh Screen
				SDL_RenderPresent(gRenderer);
			}
			closeGame();
		}
	}
	return 0;
}

//Automatic Bazooty