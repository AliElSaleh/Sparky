#include "../../../inc/graphics/buffers/VertexArray.h"

namespace sparky
{
	namespace graphics
	{
		// Default
		VertexArray::VertexArray() noexcept
		{
			glGenVertexArrays(1, &mArrayID);
		}

		// Copy constructor
		VertexArray::VertexArray(const VertexArray &other)
		{
			mArrayID = other.mArrayID;
			mBuffers = other.mBuffers;
		}

		// Copy assignment
		VertexArray &VertexArray::operator=(const VertexArray &other) noexcept
		{
			if (this != &other)
			{
				for (auto &mBuffer : mBuffers)
					delete mBuffer;

				mArrayID = other.mArrayID;
				mBuffers = other.mBuffers;
			}

			return *this;
		}

		// Move constructor
		VertexArray::VertexArray(VertexArray &&other) noexcept
		{
			mArrayID = other.mArrayID;
			mBuffers = other.mBuffers;

			other.mArrayID = 0;
			other.mBuffers.clear();
		}

		// Move assignment
		VertexArray &VertexArray::operator=(VertexArray &&other) noexcept
		{
			if (this != &other)
			{
				for (auto &mBuffer : mBuffers)
					delete mBuffer;

				other.mArrayID = 0;
			}

			return *this;
		}

		VertexArray::~VertexArray()
		{
			for (auto &mBuffer : mBuffers)
				delete mBuffer;
		}

		void VertexArray::AddBuffer(Buffer *buffer, const GLuint index) const
		{
			Bind();
			buffer->Bind();

			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, nullptr);

			Buffer::UnBind();
			UnBind();
		}

		void VertexArray::Bind() const
		{
			glBindVertexArray(mArrayID);
		}

		void VertexArray::UnBind()
		{
			glBindVertexArray(0);
		}

	}
}
