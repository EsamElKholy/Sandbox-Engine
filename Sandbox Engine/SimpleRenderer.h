#pragma once

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

			private:
				Shapes::GLGeneralMesh *m_Mesh;
			};

		}
	}
}