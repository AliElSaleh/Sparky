#pragma once
#include <glfw3.h>
#include <iostream>

namespace sparky
{
	namespace graphics
	{
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
			inline int GetHeight() const { return m_Height; };

		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;

		private:
			bool Init();
		};

	}
}