#include "Visualizer.h"
#include "Colors.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "CollisionVolumeBSphere.h"
#include "Scene.h"
#include "SceneManager.h"

Visualizer* Visualizer::ptrInstance = nullptr;

Visualizer::Visualizer() {
	DEFAULT_COLOR = Colors::BLUE;
	WFUnitSphere = new GraphicsObject_WireframeConstantColor(ModelManager::Get("sphere"), ShaderManager::Get("colorConstant"), DEFAULT_COLOR);
	itr = vCommands.begin();
}

Visualizer::~Visualizer() {
	delete Instance().WFUnitSphere;
	DebugMsg::out("deleted visualizer singleton\n");
}

void Visualizer::privRenderBSphere(Matrix& S) {
	Instance().WFUnitSphere->SetWorld(S);
	Instance().WFUnitSphere->Render(SceneManager::GetCurrentScene()->GetCurrentCamera());
}

void Visualizer::VisualizeAll() {
	//execute commands to render all bspheres
	for (VisualizeList::iterator it = Instance().vCommands.begin();
		it != Instance().vCommands.end(); it++) {
		Instance().WFUnitSphere->pWireColor->set(it->C);
		Instance().privRenderBSphere(it->w);
	}

	Instance().vCommands.clear();
	Instance().itr = Instance().vCommands.begin();
}

void Visualizer::ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col) {
	//bsphere update
	float r = S.GetRadius();
	Vect c = S.GetCenter();
	Vect vBSSize = (r * Vect(1, 1, 1));
	Vect vBSPos = c;
	
	// Adjust the Bounding Sphere's position and scale to fit matrices center and scale
	Matrix worldBS = Matrix(SCALE, vBSSize) * Matrix(TRANS, vBSPos); // *world;
	
	//add a command for a bsphere to render
	Instance().vCommands.insert(Instance().itr, VisualBSphere(col, worldBS));
}

void Visualizer::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}