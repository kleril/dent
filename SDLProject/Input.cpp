/*
COPYRIGHT TIMOTHY ODD 07/11/2014

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Input.h"
#include <string>

int m_mouseX;
int m_mouseY;
bool running;
bool m_leftMouse;
bool lMousePressFired;
bool m_rightMouse;
bool rMousePressFired;
bool lastEventKeyRelease;
bool lastEventKeyPress;
int releasedKey;

Input::Input(void)
{
	int m_MouseX = 0;
	int m_MouseY = 0;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	bool lastEventKeyRelease = false;
	bool lastEventKeyPress = false;
	int releasedKey = NULL;
}

void Input::handleInput(SDL_Event evt)
{
	while (SDL_PollEvent(&evt))
	{
		switch (evt.type)
		{
		case SDL_QUIT:
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (evt.button.button == SDL_BUTTON_LEFT)
			{
				m_leftMouse = true;
				lMousePressFired = false;
			}
			else
			{
				m_rightMouse = true;
				rMousePressFired = false;
			}
			m_mouseX = evt.button.x;
			m_mouseY = evt.button.y;
			break;
		case SDL_MOUSEBUTTONUP:
			if (evt.button.button == SDL_BUTTON_LEFT)
			{
				m_leftMouse = false;
			}
			else
			{
				m_rightMouse = false;
			}
			m_mouseX = evt.button.x;
			m_mouseY = evt.button.y;
			break;
		case SDL_MOUSEMOTION:
			m_mouseX = evt.button.x;
			m_mouseY = evt.button.y;
			break;
		case SDL_KEYUP:
			releasedKey = evt.key.keysym.scancode;
			lastEventKeyRelease = true;
			lastEventKeyPress = false;
			state = SDL_GetKeyboardState(NULL);
		case SDL_KEYDOWN:
			lastEventKeyPress = true;
			lastEventKeyRelease = false;
			state = SDL_GetKeyboardState(NULL);
		default:
			state = SDL_GetKeyboardState(NULL);
		}
	}
}


bool Input::keyPressed(int key)
{
	return state[key];
}

//Returns Input::state[int] of the last key pressed
bool Input::keyReleased(int key)
{
	if (releasedKey == key)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::leftMousePressed()
{
	return m_leftMouse;
}


bool Input::rightMousePressed()
{
	return m_rightMouse;
}

//PressedOnce methods only return true once per click.
bool Input::rightMousePressedOnce()
{
	if (rMousePressFired == false)
	{
		rMousePressFired = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool Input::leftMousePressedOnce()
{
	if (lMousePressFired == false)
	{
		lMousePressFired = true;
		return true;
	}
	else
	{
		return false;
	}
}


int Input::getMousePositionX()
{
	return m_mouseX;
}


int Input::getMousePositionY()
{
	return m_mouseY;
}

bool Input::lastEventWasKeyRelease()
{
	return lastEventKeyRelease;
}

bool Input::lastEventWasKeyPress()
{
	return lastEventKeyPress;
}