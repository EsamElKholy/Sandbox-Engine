#include "SimpleGLShader.h"

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Rendering
		{

			SimpleGLShader::SimpleGLShader()
			{

			}


			SimpleGLShader::~SimpleGLShader()
			{
			}

			void SimpleGLShader::AddShader(char *Path, const int &Type)
			{
				if (!m_ShaderProgramHandle)
				{
					m_ShaderProgramHandle = glCreateProgram();
				}

				unsigned int shader;

				if (Type == VERTEX_SHADER)
				{
					shader = glCreateShader(GL_VERTEX_SHADER);
				}
				else if(Type == FRAGMENT_SHADER)
				{
					shader = glCreateShader(GL_FRAGMENT_SHADER);
				}

				char * shaderData = ReadFromFile(Path);

				glShaderSource(shader, 1, &shaderData, NULL);
				glCompileShader(shader);

				int success;
				char log[512];

				glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

				if (!success)
				{
					glGetShaderInfoLog(shader, 512, NULL, log);
					std::cout << "Couldn't Compile shader: \n" << log << "\n";
					system("PAUSE");
				}

				glAttachShader(m_ShaderProgramHandle, shader);

				glDeleteShader(shader);
			}

			void SimpleGLShader::CompileShader()
			{
				glLinkProgram(m_ShaderProgramHandle);

				int success;
				char log[512];

				glGetProgramiv(m_ShaderProgramHandle, GL_LINK_STATUS, &success);

				if (!success)
				{
					glGetProgramInfoLog(m_ShaderProgramHandle, 512, NULL, log);
					std::cout << "Couldn't link shader: \n" << log << "\n";
					system("PAUSE");
				}
			}

			void SimpleGLShader::ActivateShader()
			{
				glUseProgram(m_ShaderProgramHandle);
			}

			char* SimpleGLShader::ReadFromFile(char *Path)
			{
				FILE *file;
				fopen_s(&file, Path, "r");

				if (!file){
					std::cout << "Failed to open file!!" << std::endl;
					return NULL;
				}

				fseek(file, 0, SEEK_END);
				unsigned long length = ftell(file);

				char *data = new char[length + 1];
				memset(data, 0, length + 1);

				fseek(file, 0, SEEK_SET);
				fread_s(data, length + 1, 1, length, file);

				fclose(file);

				return data;
			}
		}
	}
}
