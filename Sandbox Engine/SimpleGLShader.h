#pragma once

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "GL\glew.h"

#define VERTEX_SHADER 0
#define FRAGMENT_SHADER 1

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Rendering
		{

			class SimpleGLShader
			{
			public:
				SimpleGLShader();
				~SimpleGLShader();

			public:
				void AddShader(char *Path, const int &Type);
				void CompileShader();
				inline unsigned int GetHandle() const{ return m_ShaderProgramHandle; }
				void ActivateShader();

			private:
				char* ReadFromFile(char *Path);

			private:				
				unsigned int m_ShaderProgramHandle = NULL;
			};

		}
	}
}