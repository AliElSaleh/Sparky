#include "inc\graphics\Window.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 1280, 720);
	glClearColor(0.2, 0.3, 0.8, 1);

	while (!window.Closed())
	{
		window.Clear();
		
		glBegin(GL_QUADS);
		glVertex2d(-0.5, -0.5);
		glVertex2d(-0.5,  0.5);
		glVertex2d( 0.5,  0.5);
		glVertex2d( 0.5, -0.5);
		glEnd();

		window.Update();
	}

	return 0;
}