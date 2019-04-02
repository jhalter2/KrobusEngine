#ifndef _SceneManagerAttorney
#define _SceneManagerAttorney

#include "SceneManager.h"

class Scene;

class SceneManagerAttorney {
	friend class KrobusEngine;
	friend class SceneChangeCommand;
private:
	static void Terminate() { SceneManager::Terminate(); }
	static void Update() { SceneManager::Update(); };
	static void Draw() { SceneManager::Draw(); };
	static void SwitchToNextScene(Scene* pScene) { SceneManager::SwitchToNextScene(pScene); };
};

#endif _SceneManagerAttorney
