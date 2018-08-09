#include "inc/graphics/Window.h"
#include "inc/graphics/Shader.h"
#include "inc/maths/maths.h"
#include "Utils/FileUtils.h"
#include "inc/graphics/buffers/IndexBuffer.h"
#include "inc/graphics/buffers/VertexArray.h"

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
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat coloursA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat coloursB[] =
	{
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.AddBuffer(new Buffer(coloursA, 4 * 4, 4), 1);
	sprite2.AddBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.AddBuffer(new Buffer(coloursB, 4 * 4, 4), 1);

	const auto orthographic = Matrix4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	auto colour = Vector4(0.2f, 0.3f, 0.8f, 1.0f);
	auto lightPos = Vector2(4.0f, 1.5f);

	Shader shader("src/graphics/basic.vert", "src/graphics/basic.frag");
	shader.Enable();
	shader.SetUniformMatrix4("pr_matrix", orthographic);
	shader.SetUniformMatrix4("ml_matrix", Matrix4::MakeTranslation(Vector3(4, 3, 0)));
	
	shader.SetUniform2f("light_pos", lightPos);
	shader.SetUniform4f("colour", colour);


	while (!window.Closed())
	{
		Window::Clear();


		double x, y;
		window.GetMousePosition(x, y);
		Vector2 vector(float(x * 16.0f / 1280.0f), float(9.0f - y * 9.0f / 720.0f));
		shader.SetUniform2f("light_pos", vector);

		sprite1.Bind();
		ibo.Bind();
		shader.SetUniformMatrix4("ml_matrix", Matrix4::MakeTranslation(Vector3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, nullptr);
		IndexBuffer::UnBind();
		VertexArray::UnBind();

		sprite2.Bind();
		ibo.Bind();
		shader.SetUniformMatrix4("ml_matrix", Matrix4::MakeTranslation(Vector3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, nullptr);
		IndexBuffer::UnBind();
		VertexArray::UnBind();


		window.Update();
	}

	return 0;
}