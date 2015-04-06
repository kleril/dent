#include <SDL.h>
#include <string>
#include <sstream>

class Window{
public:
	Window();
	bool init();
	SDL_Renderer* createRenderer();
	bool handleEvent(SDL_Event& e);
	void free();

	int getWidth();
	int getHeight();

	bool hasMouseFocus();
	bool hasKeyboardFocus();
	bool isMinimized();

protected:

private:
	//Window data
	SDL_Window* window;

	//Window dimensions
	int width;
	int height;

	//Window focus
	bool mouseFocus;
	bool keyboardFocus;
	bool fullScreen;
	bool minimized;
};