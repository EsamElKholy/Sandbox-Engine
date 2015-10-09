#pragma once

#include "SimpleRenderer.h"

class TestGame
{
public:
	TestGame();
	~TestGame();

public:
	void InitGame();
	void Update();
	void Render();

private:
	Dimension::GraphicsLayer::Rendering::SimpleRenderer *renderer;
};

