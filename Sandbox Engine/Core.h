#pragma once

#include "OpenglWindow.h"
#include "TestGame.h"

namespace Dimension
{
	namespace BaseLayer
	{
		namespace EngineCore{

			class Core
			{
			public:
				Core();
				~Core();
			public:
				void InitEngine(const char* Title, const short &Width, const short &Height, const char* Mode);
				void RunEngine();
				void StopEngine();

				void MainLoop();

				void DestroyEverything();

			public:
				Window::OpenglWindow *m_Window;
				TestGame *game;
				bool m_Running;
			};
		}
	}
}