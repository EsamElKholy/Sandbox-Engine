#pragma once

#include "GL\glew.h"
#include "GLRenderable.h"

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Shapes
		{

			class GLGeneralMesh : public GLRenderable
			{
			public:
				GLGeneralMesh();
				~GLGeneralMesh();

			public:
				virtual void InitShape() override;
				virtual inline int GetHandle() const override;
				virtual void Draw() override;

			private:
				virtual void Bind() override;
				virtual void Unbind() override;
			public:
				void StoreData(float *Vertices, int *Elements, const int &VerticesSize, const int &ElementsSize);

			private:
				unsigned int m_EBO, m_VBO, m_VAO;
				float *m_Vertices;
				int *m_Elements;
				int m_VerticesSize, m_ElementsSize;
			};
			
		}
	}
}