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

#pragma once

#include <SDL.h>

class Input
{
public:
	Input();
	void handleInput(SDL_Event evt);
	bool keyPressed(int key);
	bool keyReleased(int key);
	bool leftMousePressed();
	bool leftMousePressedOnce();
	bool rightMousePressed();
	bool rightMousePressedOnce();
	int getMousePositionX();
	int getMousePositionY();
	bool lastEventWasKeyRelease();
	bool lastEventWasKeyPress();
	
protected:

private:
	int releasedKey;
	int m_mouseX;
	int m_mouseY;
	const Uint8 *state;
	bool lastEventKeyRelease;
	bool lastEventKeyPress;
};