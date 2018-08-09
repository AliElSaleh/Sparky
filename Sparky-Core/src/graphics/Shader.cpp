#include "../../inc/graphics/Shader.h"
#include "../../inc/maths/maths.h"
#include <vector>
#include <iostream>

namespace sparky
{
	namespace graphics
	{
		Shader::Shader(const char *vertexPath, const char *fragmentPath)
			: mVertexPath(vertexPath), mFragmentPath(fragmentPath)
		{
			mShaderID = Load();
		}

		// Copy constructor
		Shader::Shader(const Shader & other)
		{
			mFragmentPath = other.mFragmentPath;
			mShaderID = other.mShaderID;
			mVertexPath = other.mVertexPath;			
		}

		// Copy assignment
		Shader &Shader::operator=(const Shader & other)
		{
			if (this != &other)
			{
				delete mFragmentPath;
				delete mVertexPath;

				mShaderID = other.mShaderID;
				mFragmentPath = other.mFragmentPath;
				mVertexPath = other.mVertexPath;
			}

			return *this;
		}

		// Move constructor
		Shader::Shader(Shader &&other) noexcept
		{
			mFragmentPath = other.mFragmentPath;
			mShaderID = other.mShaderID;
			mVertexPath = other.mVertexPath;

			other.mFragmentPath = nullptr;
			other.mVertexPath = nullptr;
			other.mShaderID = 0;
		}

		// Move assignment
		Shader &Shader::operator=(Shader && other) noexcept
		{
			if (this != &other)
			{
				delete mFragmentPath;
				delete mVertexPath;

				mShaderID = other.mShaderID;
				mFragmentPath = other.mFragmentPath;
				mVertexPath = other.mVertexPath;
			}

			return *this;
		}

		Shader::~Shader()
		{
			glDeleteProgram(mShaderID);
		}

		void Shader::Enable() const
		{
			glUseProgram(mShaderID);
		}

		void Shader::Disable()
		{
			glUseProgram(0);
		}

		GLuint Shader::GetShaderID() const
		{
			return mShaderID;
		}

		GLint Shader::GetUniformLocation(const GLchar *name) const
		{
			return glGetUniformLocation(mShaderID, name);
		}

		void Shader::SetUniformMatrix4(const GLchar *name, const Matrix4 &matrix) const
		{
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::SetUniform1f(const GLchar *name, const float value) const
		{
			glUniform1f(GetUniformLocation(name), value);
		}

		void Shader::SetUniform1i(const GLchar *name, const int value) const
		{
			glUniform1i(GetUniformLocation(name), value);
		}

		void Shader::SetUniform2f(const GLchar *name, Vector2 &vector) const
		{
			glUniform2f(GetUniformLocation(name), vector.x, vector.y);
		}

		void Shader::SetUniform3f(const GLchar *name, Vector3 &vector) const
		{
			glUniform3f(GetUniformLocation(name), vector.x, vector.y, vector.z);
		}

		void Shader::SetUniform4f(const GLchar *name, Vector4 &vector) const
		{
			glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}

		GLuint Shader::Load() const
		{
			const auto program = glCreateProgram();
			const auto vertex = glCreateShader(GL_VERTEX_SHADER);
			const auto fragment = glCreateShader(GL_FRAGMENT_SHADER);

			auto vertexSourceString = read_file(mVertexPath);
			auto fragmentSourceString = read_file(mFragmentPath);

			auto vertexSource = vertexSourceString.c_str();
			auto fragmentSource = fragmentSourceString.c_str();

			// Vertex
			glShaderSource(vertex, 1, &vertexSource, nullptr);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			// Fragment
			glShaderSource(fragment, 1, &fragmentSource, nullptr);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return 1;
		}
	}
}
