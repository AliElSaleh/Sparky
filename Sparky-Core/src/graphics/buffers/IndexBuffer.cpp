#include "../../../inc/graphics/buffers/IndexBuffer.h"

namespace sparky
{
	namespace graphics
	{
		IndexBuffer::IndexBuffer(GLushort *data, const GLsizei count)
			: mCount(count)
		{
			glGenBuffers(1, &mBufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::Bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBufferID);
		}

		void IndexBuffer::UnBind()
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}
}
