#include "KrobusSprite.h"
#include "AzulCore.h"
#include "ImageManager.h"
#include "ShaderManager.h"
#include "ModelManager.h"
#include <string>

KrobusSprite::KrobusSprite(std::string imgKey) {
	Image* pImage = ImageManager::Get(imgKey);

	pGOSprite = new GraphicsObject_Sprite(ModelManager::Get("spriteModel"), ShaderManager::Get("spriteShader"),
		pImage, pImage->pImageRect);

	//loading default settings for the sprite
	SetScaleFactor(1.0f, 1.0f);
	SetAngle(0.0f);
	SetCenter(0.5f, 0.5f);
	SetPosition(0.0f, 0.0f);
}

KrobusSprite::KrobusSprite(Image* pImg) {
	pGOSprite = new GraphicsObject_Sprite(ModelManager::Get("spriteModel"), ShaderManager::Get("spriteShader"),
		pImg, pImg->pImageRect);

	//loading default settings for the sprite
	SetScaleFactor(1.0f, 1.0f);
	SetAngle(0.0f);
	SetCenter(0.5f, 0.5f);
	SetPosition(0.0f, 0.0f);
}

KrobusSprite::~KrobusSprite() {
	delete pGOSprite;
}

void KrobusSprite::Render(Camera* pCam) {
	UpdateWorld();
	pGOSprite->Render(pCam);
}

void KrobusSprite::UpdateWorld() {
	Matrix Scale;
	Scale.set(SCALE, scaleX, scaleY, 1.0f);
	Matrix RotZ;
	RotZ.set(ROT_Z, angle);
	Matrix CenterOffset;
	CenterOffset = Matrix(TRANS, -centerX, -centerY, 0);
	Matrix Trans;
	Trans.set(TRANS, pGOSprite->origPosX, pGOSprite->origPosY, 0.0f);
	Matrix world = Scale * CenterOffset * RotZ * Trans;
	pGOSprite->SetWorld(world);
}

float KrobusSprite::GetAngle() {
	return angle;
}

void KrobusSprite::SetAngle(float a) {
	angle = a;
}

void KrobusSprite::SetCenter(float offsetx, float offsety) {
	centerX = offsetx;
	centerY = offsety;
}

void KrobusSprite::SetPosition(float x, float y) {
	pGOSprite->origPosX = x;
	pGOSprite->origPosY = y;
}

void KrobusSprite::SetScaleFactor(float scalex, float scaley) {
	scaleX = scalex;
	scaleY = scaley;
}

void KrobusSprite::SetScalePixel(float width, float height) {
	SetScaleFactor(width / pGOSprite->origWidth, height / pGOSprite->origHeight);
}

float KrobusSprite::GetSpriteWidth() {
	return pGOSprite->origWidth;
}

float KrobusSprite::GetSpriteHeight() {
	return pGOSprite->origHeight;
}
