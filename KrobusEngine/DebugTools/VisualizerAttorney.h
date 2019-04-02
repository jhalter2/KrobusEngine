#ifndef _VisualizerAttorney
#define _VisualizerAttorney

#include "Visualizer.h"

class VisualizerAttorney {
	friend class KrobusEngine;

private:
	static void Terminate() { Visualizer::Terminate(); }
	static void VisualizeAll() { Visualizer::VisualizeAll(); }
};

#endif _VisualizerAttorney
