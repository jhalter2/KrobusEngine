#ifndef _SceneNull
#define _SceneNull

#include "Scene.h"

class SceneNull : public Scene, public Align16 {
	virtual void Initialize() {};
	virtual void SceneEnd() {};
};
#endif _SceneNull
