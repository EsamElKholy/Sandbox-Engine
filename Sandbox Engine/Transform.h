#pragma once

#include "MathLibsWrapper.h"

namespace Dimension
{
	namespace AllRounderLayer
	{
		namespace Movement
		{

			class Transform
			{
			public:
				Transform();
				~Transform();

				mat4 GetModelMatrix();// const vec3 &Translation, const vec3 &Rotation, const vec3 &Scale);

			public:
				mat4 m_TranslationMatrix;
				mat4 m_RotationMarix;
				mat4 m_ScaleMatrix;

			};

		}
	}
}