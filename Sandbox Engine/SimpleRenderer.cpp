#include "SimpleRenderer.h"

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Rendering
		{

			SimpleRenderer::SimpleRenderer()
			{
			}

			SimpleRenderer::SimpleRenderer(Shapes::GLGeneralMesh *Mesh)
			{
				m_Mesh = Mesh;
			}

			SimpleRenderer::~SimpleRenderer()
			{
				if (m_Mesh)
					delete m_Mesh;
			}

			void SimpleRenderer::Render()
			{
				m_Mesh->Draw();
			}

		}
	}
}