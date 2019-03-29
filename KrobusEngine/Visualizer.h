#ifndef _Visualizer
#define _Visualizer

#include "AzulCore.h"
#include <list>

class CollisionVolumeBSphere;

class Visualizer : public Align16 {
private:
	static Visualizer* ptrInstance;

	Visualizer();
	Visualizer(const Visualizer&) = delete;
	Visualizer& operator=(const Visualizer&) = delete;
	~Visualizer();

	static Visualizer& Instance() {
		if (!ptrInstance)
			ptrInstance = new Visualizer;
		return *ptrInstance;
	};

	Vect DEFAULT_COLOR;
	GraphicsObject_WireframeConstantColor* WFUnitSphere;

	void privRenderBSphere(Matrix& S);

	friend class VisualizerAttorney;

	static void Terminate();

	//visualize through command system
	class VisualBSphere {
		VisualBSphere(const Vect& c, Matrix wr)
			:C(c), w(wr) {}
		const Vect& C;
		Matrix w;
		friend class Visualizer;
	};
	using VisualizeList = std::list<VisualBSphere>;
	VisualizeList vCommands;
	VisualizeList::iterator itr;
	static void VisualizeAll();
public:
	static void ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col);
};

#endif _Visualizer
