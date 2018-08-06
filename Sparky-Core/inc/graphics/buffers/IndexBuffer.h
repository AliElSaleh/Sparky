#pragma once

#include <GL/glew.h>

namespace sparky
{
	namespace graphics
	{
		class IndexBuffer
		{
		public:
			IndexBuffer(GLushort *data, GLsizei count);

			void Bind() const;
			void UnBind() const;

			inline GLuint GetCount() const { return mCount; }

		private:
			GLuint mBufferID;
			GLuint mCount;
		};
	}
}
