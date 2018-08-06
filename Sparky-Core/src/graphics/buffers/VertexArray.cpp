#include "../../inc/graphics/buffers/VertexArray.h"

namespace sparky
{
	namespace graphics
	{
		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &mArrayID);
		}

		VertexArray::~VertexArray()
		{
			for (int i = 0; i < mBuffers.size(); i++)
				delete mBuffers[i];
		}

		void VertexArray::AddBuffer(Buffer *buffer, const GLuint index) const
		{
			Bind();
			buffer->Bind();

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, nullptr);

			buffer->UnBind();
			UnBind();
		}

		void VertexArray::Bind() const
		{
			glBindVertexArray(mArrayID);
		}

		void VertexArray::UnBind() const
		{
			glBindVertexArray(0);
		}

	}
}
