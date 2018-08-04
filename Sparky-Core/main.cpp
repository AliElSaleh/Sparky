#include "inc\graphics\Window.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 1280, 720);
	glClearColor(0.2, 0.3, 0.8, 1);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vector2 vector2d(1, 2);
	Vector3 vector3d(1, 2, 3);
	Vector4 color(1, 2, 3, 4);

	Matrix4 position = Matrix4::MakeTranslation(Vector3(2, 3, 4));
	position *= Matrix4::MakeIdentity();

	position.elements[12] = 2.0f;

	Vector4 c0 = position.columns[3];
	std::cout << c0 << std::endl;

	while (!window.Closed())
	{
		window.Clear();
		
		std::cout << vector2d << std::endl;

		float x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

		glBegin(GL_QUADS);
		glVertex2d(-0.5, -0.5);
		glVertex2d(-0.5,  0.5);
		glVertex2d( 0.5,  0.5);
		glVertex2d( 0.5, -0.5);
		glEnd();

		//glDrawArrays(GL_ARRAY_BUFFER, 0, 0);

		window.Update();
	}

	return 0;
}