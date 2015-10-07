#include "Core.h"

namespace Dimension
{
	namespace BaseLayer
	{
		namespace EngineCore{
			Core::Core()
			{
			}


			Core::~Core()
			{
			}
			
			void Core::InitEngine(const char* Title, const short &Width, const short &Height, const char* Mode)
			{
				m_Window = new Window::OpenglWindow();
				if (!m_Window->Init(Title ,Width ,Height ,Mode))
				{
					m_Window->Destroy();
				}
			}
			void Core::RunEngine()
			{				
				m_Running = true;
				MainLoop();
			}

			void Core::StopEngine()
			{
				m_Running = false;
				DestroyEverything();
			}

			void Core::MainLoop()
			{
				while (m_Running)
				{
					if (m_Window->IsClosed())
					{
						StopEngine();
					}

					m_Window->Update();
					m_Window->Render();
				}

				DestroyEverything();
			}

			void Core::DestroyEverything()
			{
				m_Window->Destroy();
			}
		}
	}
}