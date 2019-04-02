#include "KrobusEngine.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "ModelManager.h"
#include "SceneManager.h"
#include "ImageManager.h"
#include "SpriteFontManager.h"
#include "SceneDemo.h"
#include "MovementDemo.h"
#include "CameraDemo.h"
#include "TankDemoStart.h"
#include "SpriteDemo.h"
#include "Scene.h"
#include "MenuScene.h"

void KrobusEngine::LoadResources() {
	//load the sprite model
	ModelManager::Load("spriteModel", Model::PreMadedeModels::UnitSquareXY);

	ModelManager::Load("modelAxis", ModelManager::Axis);
	ModelManager::Load("modelPlane", ModelManager::Plane);
	ModelManager::Load("modelSpaceFrigate", ModelManager::Frigate);
	ModelManager::Load("modelEnemyTank", ModelManager::Enemy);
	ModelManager::Load("sphere", Model::PreMadedeModels::UnitSphere);
	ModelManager::Load("modelCottage", ModelManager::Cottage);
	ModelManager::Load("modelTank", ModelManager::Player);

	//load sprite shader
	ShaderManager::Load("spriteShader", ShaderManager::Sprite);

	ShaderManager::Load("colorConstantBullet", ShaderManager::ColorConstant);
	ShaderManager::Load("playerShader", ShaderManager::TextureLight);
	ShaderManager::Load("enemyShader", ShaderManager::TextureLight);
	ShaderManager::Load("colorConstant", ShaderManager::ColorConstant);
	ShaderManager::Load("colorNoTexture", ShaderManager::Color);
	ShaderManager::Load("textureFlat", ShaderManager::Texture);
	ShaderManager::Load("textureLight", ShaderManager::TextureLight);

	TextureManager::Load("spaceFrigate", "space_frigate.tga");
	TextureManager::Load("textPlane", "grid.tga");
	TextureManager::Load("playerColor", "BlueTexture.tga");
	TextureManager::Load("enemyColor", "RedTexture.tga");
	TextureManager::Load("stitchTexture", "stitch.tga");
	TextureManager::Load("terrainTexture", "ground.tga");
	TextureManager::Load("cottageTexture", "Cabintexture.tga");

	ImageManager::Load("stitchImage", TextureManager::Get("stitchTexture"));

	//load the font texture
	TextureManager::Load("fontTex", "FontSheet.tga");
	SpriteFontManager::Load("font1", "FontXML.xml");

	//SceneManager::SetStartScene(new MovementDemo());
	//SceneManager::SetStartScene(new CameraDemo());
	//SceneManager::SetStartScene(new SceneDemo());
	//SceneManager::SetStartScene(new SpriteDemo());
	SceneManager::SetStartScene(new TankDemoStart());
}
