#include "EnemyTank.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "CameraManager.h"
#include "BulletFactory.h"
#include "EVENT_TYPE.h"
#include "SceneManager.h"
#include "SceneDemo.h"
#include "CollisionVolumeBSphere.h"
#include "Scene.h"
#include "SceneManager.h"
#include "EnemyFactory.h"
#include "EnemyManager.h"
#include "Player.h"
#include "EnemyBulletFactory.h"
#include "PlayerScore.h"

EnemyTank::EnemyTank() {
	//the light for the object
	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 20.0f, 1.0f, 1.0f);
	pGObj_Tank = new GraphicsObject_TextureLight(ModelManager::Get("modelTank"), ShaderManager::Get("enemyShader"),
		TextureManager::Get("enemyColor"), LightColor, LightPos);

	SetColliderModel(ModelManager::Get("modelTank"));
}

EnemyTank::~EnemyTank() {
	DebugMsg::out("enemy deleted\n");
}

void EnemyTank::Initialize(bool rot, Vect posi) {
	world = Matrix(IDENTITY);
	world = Matrix(SCALE, 400, 400, 400);

	tankScale.set(SCALE, MODEL_SCALE, MODEL_SCALE, MODEL_SCALE);
	tankRot.set(IDENTITY);
	tankRot *= Matrix(ROT_X, TANK_ROT_ADJUST);
	if (!rot) {
		tankRot *= Matrix(ROT_Y, TANK_ROT_ADJUST);
	}
	else {
		tankRot *= Matrix(ROT_Y, TANK_RIGHT_ROT);
	}
	tankPos = posi;
	world = tankScale * tankRot * Matrix(TRANS, tankPos);
	pGObj_Tank->SetWorld(world);
}

void EnemyTank::Draw() {
	pGObj_Tank->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
}

void EnemyTank::Update() {
	tankPos += Vect(0, 1, 0) * tankRot * tankTransSpeed;
	// tank adjust matrix
	world = tankScale * tankRot * Matrix(TRANS, tankPos);
	pGObj_Tank->SetWorld(world);
	this->UpdateCollisionData(world);
}

void EnemyTank::Collision(Player*) {
	DebugMsg::out("enemy hit by player and died\n");
	PlayerScore::UpdateScore(10.0f);
	SubmitAlarmDeregistration(0);
	SubmitExit();
}

void EnemyTank::Collision(Bullet*) {
	DebugMsg::out("enemy hit by bullet and died\n");
	PlayerScore::UpdateScore(10.0f);
	SubmitAlarmDeregistration(0);
	SubmitExit();
}

void EnemyTank::Alarm0() {
	DebugMsg::out("enemy exited after 60 seconds\n");
	SubmitExit();
}

void EnemyTank::Alarm1() {
	EnemyBulletFactory::CreateBullet(tankRot, tankPos);
	SubmitAlarmRegistration(3, 1);
}

void EnemyTank::SceneEntry() {
	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	SubmitAlarmRegistration(60, 0);
	SubmitAlarmRegistration(3, 1);
	SetCollidableGroup<EnemyTank>();
	SubmitCollisionRegistration();
	EnemyBulletFactory::CreateBullet(tankRot, tankPos);
}

void EnemyTank::SceneExit() {
	SubmitAlarmDeregistration(1);
	SubmitUpdateDeregistration();
	SubmitDrawDeregistration();
	SubmitCollisionDeregistration();
	EnemyFactory::EnemyReturn(this);
}

const CollisionVolumeBSphere& EnemyTank::GetBSphere() {
	return BSphere;
}

void EnemyTank::SetColliderModel(Model* mod) {
	pColModel = mod;
}

void EnemyTank::UpdateCollisionData(Matrix& mat) {
	BSphere.ComputeData(pColModel, mat, MODEL_SCALE);
}