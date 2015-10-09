#include "TestGame.h"


TestGame::TestGame()
{
}


TestGame::~TestGame()
{
}

void TestGame::InitGame()
{
	float vertices[] = {
		0.5f, 0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f, 0.5f, 0.0f   // Top Left 
	};

	int indices[] = {  
		0, 1, 3,  // First Triangle
		1, 2, 3   // Second Triangle
	};

	Dimension::GraphicsLayer::Shapes::GLGeneralMesh *mesh = new Dimension::GraphicsLayer::Shapes::GLGeneralMesh();
	mesh->StoreData(vertices, indices, sizeof(vertices) / 4, sizeof(indices) / 4);
	mesh->InitShape();
	renderer = new Dimension::GraphicsLayer::Rendering::SimpleRenderer(mesh);
	renderer->InitShader();
}

void TestGame::Update()
{

}

void TestGame::Render()
{
	renderer->Render();
}