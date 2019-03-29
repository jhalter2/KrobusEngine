#include "WorldPlane.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "ModelManager.h"
#include "CameraManager.h"
#include "EVENT_TYPE.h"
#include "Camera.h"
#include "SceneManager.h"
#include "TestScene.h"
#include "Scene.h"
#include "SceneManager.h"

WorldPlane::WorldPlane() {
	pGObj_Plane = new GraphicsObject_TextureFlat(ModelManager::Get("modelPlane"), ShaderManager::Get("textureFlat"), TextureManager::Get("textPlane"));
	pGObj_Axis = new GraphicsObject_ColorNoTexture(ModelManager::Get("modelAxis"), ShaderManager::Get("colorNoTexture"));

	// Creating matrices for in-world placement
	Matrix world;

	// Axis and Plane
	world = Matrix(IDENTITY);
	pGObj_Axis->SetWorld(world);
	world = Matrix(SCALE, 400, 400, 400);
	pGObj_Plane->SetWorld(world);

	SubmitDrawRegistration();

	//SubmitAlarmRegistration(1, 0);
	//SubmitAlarmRegistration(3, 1);
	//SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_PRESS);
	//SubmitKeyRegistration(AZUL_KEY::KEY_M, EVENT_TYPE::KEY_PRESS);
	//SubmitKeyRegistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_RELEASE);
	//SubmitKeyRegistration(AZUL_KEY::KEY_M, EVENT_TYPE::KEY_RELEASE);
	//SubmitKeyRegistration(AZUL_KEY::KEY_N, EVENT_TYPE::KEY_PRESS);

	SetCollidableGroup<WorldPlane>();
	SubmitCollisionRegistration();
}

void WorldPlane::Draw() {
	pGObj_Plane->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
	pGObj_Axis->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
}

void WorldPlane::KeyPressed(AZUL_KEY k) {
	switch (k)
	{
	case AZUL_KEY::KEY_SPACE:
		DebugMsg::out("SPACE pressed in WorldPlane\n");
		break;
	case AZUL_KEY::KEY_M:
		DebugMsg::out("M pressed in WorldPlane\n");
		break;
	case AZUL_KEY::KEY_N:
		DebugMsg::out("N pressed, switching to test scene\n");
		SceneManager::SetNextScene(new TestScene());
	default:
		DebugMsg::out("KEY PRESS ERROR: this message should not appear\n");
	}
}

void WorldPlane::KeyReleased(AZUL_KEY k) {
	switch (k)
	{
	case AZUL_KEY::KEY_SPACE:
		DebugMsg::out("SPACE released in WorldPlane\n");
		break;
	case AZUL_KEY::KEY_M:
		DebugMsg::out("M released in WorldPlane\n");
		break;
	default:
		DebugMsg::out("KEY PRESS ERROR: this message should not appear\n");
	}
}

void WorldPlane::Alarm0() {
	DebugMsg::out("WorldPlane: Ping Alarm0 every 1 second\n");
	SubmitAlarmRegistration(1, 0);
}

void WorldPlane::Alarm1() {
	DebugMsg::out("WorldPlane: Ping Alarm1 every 3 seconds\n");
	SubmitAlarmRegistration(3, 1);
}

WorldPlane::~WorldPlane() {
	delete pGObj_Plane;
	delete pGObj_Axis;
	DebugMsg::out("plane and axis deleted\n");
}