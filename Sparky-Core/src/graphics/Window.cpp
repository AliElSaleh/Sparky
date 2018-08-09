#include "../../inc/graphics/Window.h"

#include <iostream>

namespace sparky
{
	namespace graphics
	{
		void window_resize(GLFWwindow *window, int width, int height);
		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

		// Default
		Window::Window(): mTitle(nullptr), mWidth(1280), mHeight(720)
		{
		}

		// Overload
		Window::Window(const char *title, const int width, const int height)
			: mTitle(title), mWidth(width), mHeight(height)
		{
			mTitle = title;
			mWidth = width;
			mHeight = height;
			if (!Init())
				glfwTerminate();

			for (auto &mKey : mKeys)
				mKey = false;

			for (auto &mMouseButton : mMouseButtons)
				mMouseButton = false;
		}

		// Copy
		Window::Window(const Window &other)
		{
			mWindow = other.mWindow;
			mTitle = other.mTitle;
			mClosed = other.mClosed;
			mHeight = other.mHeight;
			mWidth = other.mWidth;
			mKeys[MAX_KEYS-1] = other.mKeys[MAX_KEYS-1];
			mMouseButtons[MAX_BUTTONS-1] = other.mMouseButtons[MAX_BUTTONS-1];
			mX = other.mX;
			mY = other.mY;
		}

		// Copy assignment
		Window &Window::operator=(Window other) noexcept
		{
			if (this != &other)
			{
				delete mTitle;
				delete[] mKeys;
				delete[] mMouseButtons;

				mTitle = other.mTitle;
				mKeys[MAX_KEYS - 1] = other.mKeys[MAX_KEYS - 1];
				mMouseButtons[MAX_BUTTONS - 1] = other.mMouseButtons[MAX_BUTTONS - 1];
			}

			return *this;
		}

		// Move
		Window::Window(Window && other) noexcept
		{
			mClosed = other.mClosed;
			mHeight = other.mHeight;
			mWidth = other.mWidth;
			mKeys[MAX_KEYS - 1] = other.mKeys[MAX_KEYS - 1];
			mMouseButtons[MAX_BUTTONS - 1] = other.mMouseButtons[MAX_BUTTONS - 1];
			mX = other.mX;
			mY = other.mY;

			mWindow = nullptr;
			mTitle = nullptr;
		}

		// Move assignment
		Window &Window::operator=(Window &&other) noexcept
		{
			if (this != &other)
			{
				delete mTitle;
				delete[] mKeys;
				delete[] mMouseButtons;

				mTitle = other.mTitle;
				mKeys[MAX_KEYS - 1] = other.mKeys[MAX_KEYS - 1];
				mMouseButtons[MAX_BUTTONS - 1] = other.mMouseButtons[MAX_BUTTONS - 1];
			}

			return *this;
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::Update()
		{
			const auto error = glGetError();
			if (error != GL_NO_ERROR)
			{
				std::cout << "OpenGL Error: " << error << std::endl;
			}

			glfwPollEvents();
			glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);
			glfwSwapBuffers(mWindow);
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(mWindow) == 1;
		}

		void Window::Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::IsKeyPressed(const unsigned int keyCode) const
		{
			// TODO: Log this
			if (keyCode >= MAX_KEYS)
				return false;

			return mKeys[keyCode];
		}

		bool Window::IsMouseButtonPressed(const unsigned int button) const
		{
			// TODO: Log this
			if (button >= MAX_BUTTONS)
				return false;

			return mMouseButtons[button];
		}

		void Window::GetMousePosition(double &x, double &y) const
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

			mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, nullptr, nullptr);
			
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

		void window_resize(GLFWwindow *window, const int width, const int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow *window, const int key, int scancode, const int action, int mods)
		{
			const auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mKeys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow * window, const int button, const int action, int mods)
		{
			const auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mMouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow * window, const double xpos, const double ypos)
		{
			const auto win = static_cast<Window*>(glfwGetWindowUserPointer(window));
			win->mX = xpos;
			win->mY = ypos;
		}

	}
}

