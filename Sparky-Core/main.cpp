#include "inc/graphics/Window.h"
#include "inc/maths/maths.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 1280, 720);
	glClearColor(static_cast<GLclampf>(0.2), static_cast<GLclampf>(0.3), static_cast<GLclampf>(0.8), static_cast<GLclampf>(1));

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	const Vector2 vector2d(1, 2);

	Matrix4 position = Matrix4::MakeTranslation(Vector3(2, 3, 4));
	position *= Matrix4::MakeIdentity();

	position.elements[12] = 2.0f;

	const Vector4 c0 = position.columns[3];
	std::cout << c0 << std::endl;

	while (!window.Closed())
	{
		window.Clear();
		
		std::cout << vector2d << std::endl;

		double x, y;
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