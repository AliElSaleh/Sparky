#include "../../../inc/graphics/buffers/Buffer.h"

namespace sparky
{
	namespace graphics
	{
		Buffer::Buffer(GLfloat *data, const GLsizei count, const GLuint componentCount)
			: mComponentCount(componentCount)
		{
			glGenBuffers(1, &mBufferID);
			glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Buffer::Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
		}

		void Buffer::UnBind()
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}
