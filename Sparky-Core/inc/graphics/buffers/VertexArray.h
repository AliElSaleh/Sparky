#pragma once

#include <vector>
#include <GL/glew.h>

#include "Buffer.h"

namespace sparky
{
	namespace graphics
	{
		class VertexArray
		{
		public:
			// Default
			VertexArray() noexcept; 

			// Copy
			VertexArray(const VertexArray &other);
			VertexArray &operator=(const VertexArray &other) noexcept;

			// Move
			VertexArray(VertexArray &&other) noexcept;
			VertexArray &operator=(VertexArray &&other) noexcept;

			~VertexArray();

			void AddBuffer(Buffer *buffer, GLuint index) const;

			void Bind() const;
			static void UnBind();

		private:
			GLuint mArrayID{};
			std::vector<Buffer*> mBuffers;
		};
	}
}
