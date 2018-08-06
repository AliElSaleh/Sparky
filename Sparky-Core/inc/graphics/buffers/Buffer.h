#pragma once

#include <GL/glew.h>

namespace sparky
{
	namespace graphics
	{
		class Buffer
		{
		public:
			Buffer(GLfloat *data, GLsizei count, GLuint componentCount);

			void Bind() const;
			static void UnBind();

			inline GLuint GetComponentCount() const { return mComponentCount; }

		private:
			GLuint mBufferID;
			GLuint mComponentCount;
		};
	}
}
