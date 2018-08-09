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
			static void UnBind();

			GLuint GetCount() const { return mCount; }

		private:
			GLuint mBufferID;
			GLuint mCount;
		};
	}
}
