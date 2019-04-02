#ifndef _WorldPlane
#define _WorldPlane

#include "GameObject.h"

class Camera;
class Frigate;

class WorldPlane : public GameObject, public Align16 {
public:
	WorldPlane();
	WorldPlane(const WorldPlane&) = delete;
	WorldPlane& operator=(const WorldPlane&) = delete;
	~WorldPlane();

	void Draw();

	virtual void Collision(Frigate*) { DebugMsg::out("Collision WorldPlane with Frigate\n"); }
private:
	GraphicsObject_TextureFlat *pGObj_Plane;
	GraphicsObject_ColorNoTexture *pGObj_Axis;

	void Alarm0();
	void Alarm1();

	void KeyPressed(AZUL_KEY k);
	void KeyReleased(AZUL_KEY k);
};
#endif _WorldPlane
