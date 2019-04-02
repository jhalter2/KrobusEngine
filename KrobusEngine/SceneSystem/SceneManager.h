#ifndef _SceneManager
#define _SceneManager

class Scene;
class SceneChangeCommand;
class SceneChangeNullCommand;
class CommandBase;

class SceneManager {
private:
	static SceneManager* ptrInstance;

	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager();

	static SceneManager& Instance() {
		if (!ptrInstance)
			ptrInstance = new SceneManager;
		return *ptrInstance;
	}; 

	friend class SceneManagerAttorney;

	Scene *CurrentScene;
	SceneChangeCommand *sc;
	SceneChangeNullCommand *nsc;
	CommandBase* cb;

	static void SwitchToNextScene(Scene *ns);

	static void Draw();
	static void Update();

	static void Terminate();
public:

	static Scene* GetCurrentScene();
	static void InitStartScene();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SceneManager::SetStartScene(Scene *ns);
	///
	/// \brief	Sets the first scene that will start when the game is run
	///
	/// \author	Jehal
	/// \date	3/4/2019
	///
	/// \param [in,out]	ns	If non-null, the ns.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetStartScene(Scene *ns);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SceneManager::SetNextScene(Scene *ns);
	///
	/// \brief	swaps to the next (already existing) scene and DELETES current scene
	///
	/// \author	Jehal
	/// \date	3/4/2019
	///
	/// \param [in,out]	ns	If non-null, the ns.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void SetNextScene(Scene *ns);
};
#endif
