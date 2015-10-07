#include "Core.h"

int main(){
	Dimension::BaseLayer::EngineCore::Core core;

	core.InitEngine("Test", 800, 800, NULL);
	core.RunEngine();

	return 0;
}