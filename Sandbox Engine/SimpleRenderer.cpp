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
				shader = new SimpleGLShader();
			}

			SimpleRenderer::~SimpleRenderer()
			{
				if (m_Mesh)
					delete m_Mesh;

				if (!shader)
					delete shader;
			}

			void SimpleRenderer::InitShader()
			{
				
				shader->AddShader("SimpleVertexShader.vert", VERTEX_SHADER);
				shader->AddShader("SimpleFragmentShader.frag", FRAGMENT_SHADER);
				shader->CompileShader();
			}

			void SimpleRenderer::Render()
			{
				shader->ActivateShader();
				m_Mesh->Draw();
			}

		}
	}
}