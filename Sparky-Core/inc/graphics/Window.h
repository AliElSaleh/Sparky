#pragma once
#include <GL\glew.h>
#include <glfw3.h>
#include <iostream>

#include "Vector2.h"

namespace sparky
{
	namespace graphics
	{
	
#define MAX_KEYS	1024
#define MAX_BUTTONS 32
	
		class Window
		{
		public:
			Window();
			Window(const char *name, int width, int height);
			~Window();

			void Clear() const;
			void Update();
			bool Closed() const;

			inline int GetWidth() const { return m_Width; };
			inline int GetHeight() const { return mHeight; };

			bool isKeyPressed(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(float &x, float &y) const;
		
		private:
			friend struct GLFWwindow;
			const char *mTitle;
			int m_Width, mHeight;
			bool mClosed;

			GLFWwindow *mWindow;

			bool mKeys[MAX_KEYS];
			bool mMouseButtons[MAX_BUTTONS];
			double mX, mY;

		private:
			bool Init();
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
		};

	}
}