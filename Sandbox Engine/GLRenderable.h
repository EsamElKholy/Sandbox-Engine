#pragma once

namespace Dimension
{
	namespace GraphicsLayer
	{
		namespace Shapes
		{

			class GLRenderable
			{
			public:
				GLRenderable() {}
				virtual ~GLRenderable() {}

			public:
				virtual void InitShape(){}
				virtual inline int GetHandle() const{ return 0; }
				virtual void Draw(){}
			private:
				virtual void Bind(){}
				virtual void Unbind(){}
			};

		}
	}
}