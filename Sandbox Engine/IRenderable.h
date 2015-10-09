#pragma once

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Shapes
		{

			class IRenderable
			{
			public:
				IRenderable() {};
				virtual ~IRenderable() {};
			
			public:
				virtual void InitShape() = 0;
				virtual inline int GetHandle() const = 0;
				virtual void Draw() = 0;
			};

		}
	}
}