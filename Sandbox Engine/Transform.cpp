#include "Transform.h"

namespace Dimension
{
	namespace AllRounderLayer
	{
		namespace Movement
		{

			Transform::Transform()
			{
			}


			Transform::~Transform()
			{
			}

			mat4 Transform::GetModelMatrix()
			{				
				return m_ScaleMatrix * m_RotationMarix * m_TranslationMatrix;
			}
		}
	}
}