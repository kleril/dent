#include <Window.h>

//Constructor
Window::Window()
{
	//Initialize non-existant window
	window = NULL;
	mouseFocus = false;
	keyboardFocus = false;
	fullScreen = false;
	minimized = false;
	width = 0;
	height = 0;
}

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool Window::init()
{
	//Create window
	window = SDL_CreateWindow("SDL Test Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window != NULL)
	{
		mouseFocus = true;
		keyboardFocus = true;
		width = SCREEN_WIDTH;
		height = SCREEN_HEIGHT;
	}

	return window != NULL;
}

SDL_Renderer* Window::createRenderer()
{
	return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

bool Window::handleEvent(SDL_Event& e)
{
	bool needsRerender = false;
	//Window event occured
	if (e.type == SDL_WINDOWEVENT)
	{
		//Caption update flag
		bool updateCaption = false;

		switch (e.window.event)
		{
		//Get new dimensions and repaint on window size change
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			width = e.window.data1;
			height = e.window.data2;
			needsRerender = true;
			break;

			//Repaint on exposure
		case SDL_WINDOWEVENT_EXPOSED:
			needsRerender = true;
			break;

			//Mouse entered window
		case SDL_WINDOWEVENT_ENTER:
			mouseFocus = true;
			updateCaption = true;
			break;

			//Mouse left window
		case SDL_WINDOWEVENT_LEAVE:
			mouseFocus = false;
			updateCaption = true;
			break;

			//Window has keyboard focus
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			keyboardFocus = true;
			updateCaption = true;
			break;

			//Window lost keyboard focus
		case SDL_WINDOWEVENT_FOCUS_LOST:
			keyboardFocus = false;
			updateCaption = true;
			break;

			//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			minimized = true;
			break;

			//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
			break;

			//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
			break;
		}

		//Update window caption with new data
		if (updateCaption)
		{
			std::stringstream caption;
			caption << "SDL Tutorial - MouseFocus:" << ((mouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((keyboardFocus) ? "On" : "Off");
			SDL_SetWindowTitle(window, caption.str().c_str());
		}
	}
	//Enter exit full screen on return key
	else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
	{
		if (fullScreen)
		{
			SDL_SetWindowFullscreen(window, SDL_FALSE);
			fullScreen = false;
		}
		else
		{
			SDL_SetWindowFullscreen(window, SDL_TRUE);
			fullScreen = true;
			minimized = false;
		}
	}
	return needsRerender;
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}

bool Window::hasMouseFocus()
{
	return mouseFocus;
}

bool Window::hasKeyboardFocus()
{
	return keyboardFocus;
}

bool Window::isMinimized()
{
	return minimized;
}

void Window::free()
{
	SDL_DestroyWindow(window);
	window = NULL;
}