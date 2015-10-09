#include "GLGeneralMesh.h"

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Shapes
		{
			GLGeneralMesh::GLGeneralMesh()
			{
			}


			GLGeneralMesh::~GLGeneralMesh()
			{
				if (m_Elements)
					delete m_Elements;
				if (m_Vertices)
					delete m_Vertices;
			}

			void GLGeneralMesh::StoreData(float *Vertices, int *Elements, const int &VerticesSize, const int &ElementsSize)
			{
				m_Vertices = Vertices;
				m_Elements = Elements;
				m_VerticesSize = VerticesSize;
				m_ElementsSize = ElementsSize;
			}

			void GLGeneralMesh::InitShape()
			{
				glGenBuffers(1, &m_VBO);
				glGenBuffers(1, &m_EBO);

				glGenVertexArrays(1, &m_VAO);

				glBindVertexArray(m_VAO);

				glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
				glBufferData(GL_ARRAY_BUFFER, m_VerticesSize * sizeof(float), m_Vertices, GL_STATIC_DRAW);

				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), 0);

				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_ElementsSize * sizeof(int), m_Elements, GL_STATIC_DRAW);

				glBindBuffer(GL_VERTEX_ARRAY, 0);
				glBindVertexArray(0);
			}

			int GLGeneralMesh::GetHandle() const
			{				
				return m_VAO;
			}

			void GLGeneralMesh::Bind()
			{
				glBindVertexArray(m_VAO);
			}

			void GLGeneralMesh::Unbind()
			{
				glBindVertexArray(0);
			}
			
			void GLGeneralMesh::Draw()
			{
				Bind();
				glDrawElements(GL_TRIANGLES, m_ElementsSize, GL_UNSIGNED_INT, 0);
				Unbind();
			}
		}
	}
}