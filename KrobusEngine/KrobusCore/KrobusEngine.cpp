//The core engine file. Contains all the necessary
//setup and closing functions for the program to
//properly functions. The engine exists within a
//DirectX framework and the start and end are called
//from there. The Update loop is contained here
//and is called from the DirectX part of the program.
//
//NOTE: The engine manages nothing of DirectX or graphics
//itself. The engine and directx portions are completely
//encapsulated from each other and only connect through the
//EngineBridge class

#include "KrobusEngine.h"
#include "ShaderManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "ModelManagerAttorney.h"
#include "EngineBridge.h"
#include "SceneManager.h"
#include "SceneManagerAttorney.h"
#include "TimeManagerAttorney.h"
#include "TerrainManagerAttorney.h"
#include <time.h>

KrobusEngine* KrobusEngine::ptrInstance = nullptr;

//-----------------------------------------------------------------------------
// Game::Initialize()
//	Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void KrobusEngine::Initialize()
{
	KrobusEngine::GameInitialize();
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//	Allows you to load all content needed for your game,
//	such as objects, graphics, etc.
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
//	This function is called once per frame
//	Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void KrobusEngine::Draw()
{
	SceneManagerAttorney::Draw();
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
	TerrainManagerAttorney::Terminate();
}

int KrobusEngine::GetTimeSeconds() {
	//public method for managers/users to use
	return Instance().GetTimeInSeconds();
}

int KrobusEngine::GetTimeInSeconds() {
	//private method for generating time
	time_t seconds;

	seconds = time(NULL);
	return (int)seconds;
}

void KrobusEngine::Run() {
	Instance().LoadContent();
	Instance().Initialize();
}

void KrobusEngine::Terminate() {
	Instance().UnLoadContent();
	delete ptrInstance;
	ptrInstance = nullptr;
}
