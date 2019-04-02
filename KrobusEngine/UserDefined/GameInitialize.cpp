#include "KrobusEngine.h"

void KrobusEngine::GameInitialize() {
	//game window setup
	KrobusEngine::SetWindowName("Krobus Engine");
	KrobusEngine::SetWidthHeight(800, 600);
	KrobusEngine::SetClear(0.4f, 0.4f, 0.8f, 1.0f);

	//use this area for one time non-graphic creation
}
