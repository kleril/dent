#pragma once

#include <Input.h>
#include <Commands.h>
#include <vector>

class InputSystem
{
public:
	
	InputSystem();
	~InputSystem();
	void inputToCommands(Input inputPass);
	void updateMousePosition(Input inputPass);
	std::vector<Commands::command> getCommands();
	std::pair<int, int> getMousePosition();

private:
	std::vector<Commands::command> commands;
	std::pair<int, int> mousePosition;
};