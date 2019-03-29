#include "AzulCore.h"
#include "KrobusEngine.h"
#include "ShaderManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "ModelManagerAttorney.h"
#include "SceneManager.h"
#include "SceneManagerAttorney.h"
#include "TimeManager.h"
#include "TimeManagerAttorney.h"
#include "VisualizerAttorney.h"
#include "ImageManagerAttorney.h"
#include "SpriteFontManagerAttorney.h"
#include "ScreenLogAttorney.h"
#include "EnemyFactoryAttorney.h"
#include "EnemyManagerAttorney.h"

KrobusEngine* KrobusEngine::ptrInstance = nullptr;

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void KrobusEngine::Initialize()
{
	KrobusEngine::GameInitialize();
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void KrobusEngine::LoadContent()
{
	KrobusEngine::LoadResources();
	SceneManager::InitStartScene();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void KrobusEngine::Update()
{
	TimeManagerAttorney::ProcessTime(KrobusEngine::GetTimeInSeconds());
	SceneManagerAttorney::Update();
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void KrobusEngine::Draw()
{
	SceneManagerAttorney::Draw();
	ScreenLogAttorney::Render();
	VisualizerAttorney::VisualizeAll();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void KrobusEngine::UnLoadContent()
{
	ShaderManagerAttorney::Terminate();
	TextureManagerAttorney::Terminate();
	ModelManagerAttorney::Terminate();
	SceneManagerAttorney::Terminate();
	TimeManagerAttorney::Terminate();
	VisualizerAttorney::Terminate();
	ImageManagerAttorney::Terminate();
	SpriteFontManagerAttorney::Terminate();
	ScreenLogAttorney::Terminate();
}

void KrobusEngine::Run() {
	Instance().run();
}

int KrobusEngine::GetWidth() {
	return Instance().getWidth();
}

int KrobusEngine::GetHeight() {
	return Instance().getHeight();
}

float KrobusEngine::GetTimeSeconds() {
	return Instance().GetTimeInSeconds();
}

void KrobusEngine::SetClear(float r, float g, float b, float a) {
	Instance().SetClearColor(r, g, b, a);
}

void KrobusEngine::SetWidthHeight(int w, int h) {
	Instance().setWidthHeight(w, h);
}

void KrobusEngine::SetWindowName(const char* name) {
	Instance().setWindowName(name);
}

void KrobusEngine::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
