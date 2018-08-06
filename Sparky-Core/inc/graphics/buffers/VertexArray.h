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
			VertexArray();
			~VertexArray();

			void AddBuffer(Buffer *buffer, GLuint index) const;

			void Bind() const;
			void UnBind() const;

		private:
			GLuint mArrayID;
			std::vector<Buffer*> mBuffers;
		};
	}
}
