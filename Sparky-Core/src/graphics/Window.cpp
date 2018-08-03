#include "..\..\inc\graphics\Window.h"

namespace sparky
{
	namespace graphics
	{
		void window_resize(GLFWwindow *window, int width, int height);
		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

		Window::Window()
		{

		}

		Window::Window(const char *name, int width, int height)
		{
			mTitle = name;
			m_Width = width;
			mHeight = height;
			if (!Init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
				mKeys[i] = false;

			for (int i = 0; i < MAX_BUTTONS; i++)
				mMouseButtons[i] = false;
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::Update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(mWindow, &m_Width, &mHeight);
			glfwSwapBuffers(mWindow);
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(mWindow) == 1;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::isKeyPressed(unsigned int keyCode) const
		{
			// TODO: Log this
			if (keyCode >= MAX_KEYS)
				return false;

			return mKeys[keyCode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			// TODO: Log this
			if (button >= MAX_BUTTONS)
				return false;

			return mMouseButtons[button];
		}

		void Window::getMousePosition(double & x, double & y) const
		{
			x = mX;
			y = mY;
		}

		bool Window::Init()
		{
			if (!glfwInit())
			{
				std::cout << "Error! Failed to initialise GLFW." << std::endl;
				return false;
			}

			mWindow = glfwCreateWindow(m_Width, mHeight, mTitle, NULL, NULL);
			
			if (!mWindow)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			} 

			glfwMakeContextCurrent(mWindow);
			glfwSetWindowUserPointer(mWindow, this);
			glfwSetWindowSizeCallback(mWindow, window_resize);
			glfwSetKeyCallback(mWindow, key_callback);
			glfwSetMouseButtonCallback(mWindow, mouse_button_callback);
			glfwSetCursorPosCallback(mWindow, cursor_position_callback);
		

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialise GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			Window *win = (Window*)glfwGetWindowUserPointer(window);
			win->mKeys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
		{
			Window *win = (Window*)glfwGetWindowUserPointer(window);
			win->mMouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
		{
			Window *win = (Window*)glfwGetWindowUserPointer(window);
			win->mX = xpos;
			win->mY = ypos;
		}

	}
}

