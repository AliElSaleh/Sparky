#include "..\..\inc\graphics\Window.h"

namespace sparky
{
	namespace graphics
	{
		void WindowResize(GLFWwindow *window, int width, int height);

		Window::Window()
		{

		}

		Window::Window(const char *name, int width, int height)
		{
			m_Title = name;
			m_Width = width;
			m_Height = height;
			if (!Init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::Init()
		{
			if (!glfwInit())
			{
				std::cout << "Error! Failed to initialise GLFW." << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			} 

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, WindowResize);
		

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialise GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		void WindowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}

