#include "../../inc/graphics/Shader.h"
#include "../../inc/maths/maths.h"
#include <vector>
#include <iostream>

namespace sparky
{
	namespace graphics
	{
		Shader::Shader(const char *vertexPath, const char *fragPath)
			: mVertexPath(vertexPath), mFragmentPath(fragPath)
		{
			mShaderID = Load();
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
			const GLuint program = glCreateProgram();
			const GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			const GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertexSourceString = read_file(mVertexPath).c_str();
			std::string fragmentSourceString = read_file(mFragmentPath).c_str();

			const char *vertexSource = vertexSourceString.c_str();
			const char *fragmentSource = fragmentSourceString.c_str();

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
