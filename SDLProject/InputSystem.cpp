#include <InputSystem.h>

//TODO: Add methods to check if mouse buttons are CURRENTLY pressed. i.e. held.

//Takes raw input & spits out commands.
//Commands are not executed by this class, just created.
//Doesn't directly do anything, just a layer of abstraction.
InputSystem::InputSystem()
{

}

InputSystem::~InputSystem()
{

}

//TODO: Turn this into a listener if this starts to cause slowdowns.
//TODO: More scancodes! More input types!

void InputSystem::inputToCommands(Input inputPass)
{
	//Empty command queue.
	commands.clear();
	//Cardinal movement. Does not add a command to the list if the opposite direction is also pressed.
	if (inputPass.keyPressed(SDL_SCANCODE_RIGHT) && !inputPass.keyPressed(SDL_SCANCODE_LEFT))
	{
		commands.push_back(Commands::command::right);
	}
	if (inputPass.keyPressed(SDL_SCANCODE_UP) && !inputPass.keyPressed(SDL_SCANCODE_DOWN))
	{
		commands.push_back(Commands::command::up);
	}
	if (inputPass.keyPressed(SDL_SCANCODE_LEFT) && !inputPass.keyPressed(SDL_SCANCODE_RIGHT))
	{
		commands.push_back(Commands::command::left);
	}
	if (inputPass.keyPressed(SDL_SCANCODE_DOWN) && !inputPass.keyPressed(SDL_SCANCODE_UP))
	{
		commands.push_back(Commands::command::down);
	}

	//Mouse input. Only adds first mouse click to the queue. Other information should be polled when necessary.
	if (inputPass.leftMousePressedOnce())
	{
		commands.push_back(Commands::command::lMouse);
	}
	if (inputPass.rightMousePressedOnce())
	{
		commands.push_back(Commands::command::rMouse);
	}
}

std::vector<Commands::command> InputSystem::getCommands()
{
	return commands;
}

void InputSystem::updateMousePosition(Input inputPass)
{
	mousePosition.first = inputPass.getMousePositionX();
	mousePosition.second = inputPass.getMousePositionY();
}

std::pair<int, int> InputSystem::getMousePosition()
{
	return mousePosition;
}