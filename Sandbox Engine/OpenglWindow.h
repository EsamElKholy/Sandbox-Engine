#pragma once

#include <iostream>
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "IScreenManager.h"

namespace Dimension 
{
	namespace BaseLayer
	{
		namespace Window
		{

			class OpenglWindow : public Dimension::BaseLayer::Managers::IScreenManager
			{
			public:
				OpenglWindow();
				~OpenglWindow();

			public:
				bool Init(const char* Title, const short &Width, const short &Height, const char* Mode);
				void Render();
				void Update();
				void Destroy();
				void Clear();
				void SetClear(const float &Red, const float &Blue, const float &Green, const float &Alpha);
				void SetOptions();
				bool IsClosed();
			private:
				GLFWwindow *m_Window;
			};
		}
	}
}