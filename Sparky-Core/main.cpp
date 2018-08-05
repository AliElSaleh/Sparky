#include "inc/graphics/Window.h"
#include "inc/graphics/Shader.h"
#include "inc/maths/maths.h"
#include "Utils/FileUtils.h"

int main()
{
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky", 1280, 720);
	glClearColor(static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(0.0f), static_cast<GLclampf>(1.0f));

	GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	const Matrix4 orthographic = Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Vector4 colour = Vector4(0.2f, 0.3f, 0.8f, 1.0f);
	Vector2 lightPos = Vector2(4.0f, 1.5f);

	Shader shader("src/graphics/basic.vert", "src/graphics/basic.frag");
	shader.Enable();
	shader.SetUniformMatrix4("pr_matrix", orthographic);
	shader.SetUniformMatrix4("ml_matrix", Matrix4::MakeTranslation(Vector3(4, 3, 0)));
	
	shader.SetUniform2f("light_pos", lightPos);
	shader.SetUniform4f("colour", colour);



	while (!window.Closed())
	{
		window.Clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.Update();
	}

	return 0;
}