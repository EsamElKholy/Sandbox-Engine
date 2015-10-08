#pragma once

#include <vector>

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
				unsigned int m_ShaderProgramHandle;
				std::vector<unsigned int> m_Shaders;
			};

		}
	}
}