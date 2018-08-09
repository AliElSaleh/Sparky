#pragma once

#include <GL/glew.h>
#include <glfw3.h>

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
			Window(const char *title, int width, int height);

			// Copy
			Window(const Window &other);
			Window &operator=(Window other) noexcept;

			// Move
			Window(Window &&other) noexcept;
			Window &operator=(Window &&other) noexcept;

			~Window();

			static void Clear();
			void Update();
			bool Closed() const;

			int GetWidth() const { return mWidth; };
			int GetHeight() const { return mHeight; };

			bool IsKeyPressed(unsigned int keyCode) const;
			bool IsMouseButtonPressed(unsigned int button) const;
			void GetMousePosition(double &x, double &y) const;
		
		private:
			friend struct GLFWwindow;
			const char *mTitle;
			int mWidth, mHeight;
			bool mClosed{};

			GLFWwindow *mWindow{};

			bool mKeys[MAX_KEYS]{};
			bool mMouseButtons[MAX_BUTTONS]{};
			double mX{}, mY{};

			bool Init();
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
		};

	}
}