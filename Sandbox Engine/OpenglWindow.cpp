#include "OpenglWindow.h"

namespace Dimension
{
	namespace BaseLayer
	{
		namespace Window
		{
			OpenglWindow::OpenglWindow(){}
			OpenglWindow::~OpenglWindow(){}

			bool OpenglWindow::Init(const char* Title, const short &Width, const short &Height, const char* Mode)
			{
				if (!glfwInit()){
					std::cout << "Failed to initialize GLFW\n";
					return false;
				}

				glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
				m_Window = glfwCreateWindow(Width, Height, Title, NULL, NULL);

				if (m_Window == NULL){
					std::cout << "Failed to create window\n";
					return false;
				}

				glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
				glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
				glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

				glfwMakeContextCurrent(m_Window);


				if (glewInit() != GLEW_OK){
					std::cout << "Failed to initialize GLEW\n";
					return false;
				}

				glewExperimental = GL_TRUE;

				//std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

				glViewport(0, 0, Width, Height);

				SetOptions();

				return true;
			}

			void OpenglWindow::SetClear(const float &Red, const float &Blue, const float &Green, const float &Alpha)
			{
				glClearColor(Red, Blue, Green, Alpha);
			}

			void OpenglWindow::SetOptions()
			{
				glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

				glFrontFace(GL_CW);
				glCullFace(GL_BACK);
				glEnable(GL_CULL_FACE);
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_DEPTH_CLAMP);
				glDepthFunc(GL_LESS);
			}
			
			void OpenglWindow::Clear()
			{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			}

			void OpenglWindow::Render()
			{
				glfwSwapBuffers(m_Window);
			}

			void OpenglWindow::Update()
			{
				glfwPollEvents();
			}

			bool OpenglWindow::IsClosed()
			{
				return glfwWindowShouldClose(m_Window);
			}

			void OpenglWindow::Destroy()
			{
				glfwTerminate();
			}
		}
	}
}