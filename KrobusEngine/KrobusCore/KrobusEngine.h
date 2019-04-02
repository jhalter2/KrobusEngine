#ifndef KROBUSENGINE_H
#define KROBUSENGINE_H

#include "AzulCore.h"

class KrobusEngine : public Engine
{
private:
	static KrobusEngine* ptrInstance;

	KrobusEngine() = default;
	KrobusEngine(const KrobusEngine&) = delete;
	KrobusEngine& operator=(const KrobusEngine&) = delete;
	//~KrobusEngine();

	static KrobusEngine& Instance() {
		if (!ptrInstance)
			ptrInstance = new KrobusEngine;
		return *ptrInstance;
	}

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();
	virtual void Draw();
	virtual void UnLoadContent();

	//user defined
	
////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	void KrobusEngine::LoadResources()
///
/// \brief	Loads outside resources
/// 		
/// 		
/// This is where the user would load any outside resources to be used in their game/scenes, and 
/// also to specify the starting scene of their game.
/// 
/// \par Example:
/// 	 
/// 	 The following is how you might load a model and set the start scene of your game
/// 	 
///			\code
///			void KrobusEngine::LoadResources()
///			{
///				//load a model
///				ModelManager::Load("modelPlane", ModelManager::Plane);
///				
///				//set the first scene of the game
///				SceneManager::SetNextScene(new SceneDemo());
///			}
///			\endcode
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////
	void LoadResources();

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	void KrobusEngine::GameInitialize()
///
/// \brief	Initialize the game window
/// 	
/// 			
/// This is where the specifications of the game window could be setup such as name and resolution
///
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////
	void GameInitialize();

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \fn	void KrobusEngine::GameEnd();
///
/// \brief	end of gme level clean up
/// 		
/// 		
/// Any extra cleanup needed at the end of the game should go here
/// DO NOT clean up any scenes or anything inside the scenes here
/// Cleaning that up should be done through the SceneEnd() method in your scene
///
/// \author	Jehal
/// \date	3/4/2019
////////////////////////////////////////////////////////////////////////////////////////////////////

	void GameEnd();


public:
	static void Run();
	static int GetWidth();
	static int GetHeight();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static float KrobusEngine::GetTimeSeconds();
	///
	/// \brief	Gets time seconds
	/// 		
	///returns the current elapsed time (in seconds) as a float since the engine has begun 		
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \returns	The time seconds.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static float GetTimeSeconds();
	
	static void SetClear(float r, float g, float b, float a);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void KrobusEngine::SetWidthHeight(int w, int h);
	///
	/// \brief	Sets width height
	///
	/// set the width and height of the display window
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	w	The width.
	/// \param	h	The height.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetWidthHeight(int w, int h);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void KrobusEngine::SetWindowName(const char* name);
	///
	/// \brief	Sets window name
	///
	/// set the name of the display window
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetWindowName(const char* name);
	static void Terminate();
};

#endif
