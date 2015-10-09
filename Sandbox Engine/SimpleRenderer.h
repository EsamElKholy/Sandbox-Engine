#pragma once

#include "SimpleGLShader.h"
#include "GLGeneralMesh.h"

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Rendering
		{

			class SimpleRenderer
			{
			public:
				SimpleRenderer();
				SimpleRenderer(Shapes::GLGeneralMesh *m_Mesh);
				~SimpleRenderer();
				
				void Render();

				void InitShader();
			private:
			private:
				Shapes::GLGeneralMesh *m_Mesh;
				SimpleGLShader *shader;
			};

		}
	}
}