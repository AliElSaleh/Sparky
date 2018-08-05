#pragma once
#include <GL/glew.h>
#include "../../Utils/FileUtils.h"

class Vector4;
class Vector3;
class Vector2;
class Matrix4;

namespace sparky
{
	namespace graphics
	{
		class Shader
		{
		public:
			Shader(const char *vertexPath, const char *fragmentPath);
			~Shader();

			void Enable() const;
			static void Disable();

			GLuint GetShaderID() const;

			void SetUniformMatrix4(const GLchar *name, const Matrix4 &matrix) const;
			void SetUniform1f(const GLchar *name, const float value) const;
			void SetUniform1i(const GLchar *name, const int value) const;
			void SetUniform2f(const GLchar *name, Vector2 &vector) const;
			void SetUniform3f(const GLchar *name, Vector3 &vector) const;
			void SetUniform4f(const GLchar *name, Vector4 &vector) const;			

		private:
			GLuint mShaderID;
			const char *mVertexPath, *mFragmentPath;
		
			GLuint Load() const;
			GLint GetUniformLocation(const GLchar *name) const;
		};
	}
}
