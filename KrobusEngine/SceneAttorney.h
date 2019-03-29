#ifndef _SceneAttorney
#define _SceneAttorney

#include "Scene.h"
#include "SceneManager.h"

class SceneAttorney {
	friend class KrobusEngine;
	friend class SceneManager;
	friend class Updatable;
	friend class Drawable;
	friend class Alarmable;
	friend class Inputable;
	friend class Collidable;
	friend class GameObject;

private:
	static UpdatableManager* GetUpdateMgr() { return &(SceneManager::GetCurrentScene()->UpdateMgr); };
	static DrawableManager* GetDrawMgr() { return &(SceneManager::GetCurrentScene()->DrawMgr); };
	static AlarmableManager* GetAlarmMgr() { return &(SceneManager::GetCurrentScene()->AlarmMgr); };
	static KeyboardEventManager* GetInputMgr() { return &(SceneManager::GetCurrentScene()->KBEventMgr); };
	static CollisionManager* GetCollisionMgr() { return &(SceneManager::GetCurrentScene()->CollisionMgr); };

	static void Update(Scene* s) { s->Update(); };
	static void Draw(Scene* s) { s->Draw(); };
	static void Initialize(Scene* s) { s->Initialize(); };
	static void SubmitCommand(Scene* p, CommandBase* cmd) { p->SubmitCommand(cmd); };
};

#endif _SceneAttorney