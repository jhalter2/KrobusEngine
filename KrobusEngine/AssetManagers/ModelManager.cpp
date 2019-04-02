#include "ModelManager.h"

ModelManager* ModelManager::ptrInstance = nullptr;

typedef std::string string;

const string ModelManager::DefaultPath = "Models/";
const string ModelManager::Axis = "Axis.azul";
const string ModelManager::Plane = "Plane.azul";
const string ModelManager::Frigate = "space_frigate.azul";
const string ModelManager::Cottage = "Cottage.azul";
const string ModelManager::Player = "Tank.azul";
const string ModelManager::Enemy = "Tank.azul";

ModelManager::~ModelManager() {
	//delete all models we created
	for (StorageMap::iterator it = storageMap.begin(); it != storageMap.end(); it++)
	{
		delete it->second;
	}
	DebugMsg::out("models deleted and now model manager deleted\n");
}

void ModelManager::privLoad(string name, string model) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR model Manager: model key '%s' already in use.\n'", name.c_str());
		assert(false && "model key already used");
	}
	else {
		string path = DefaultPath + model;
		storageMap[name] = new Model(path.c_str());
		DebugMsg::out("model Manager: model '%s' loaded.\n'", name.c_str());
	}
}

//for premade models
void ModelManager::privLoad(string name, Model premade) {
	StorageMap::iterator it = storageMap.find(name);

	if (it != storageMap.end()) {
		DebugMsg::out("ERROR model Manager: model key '%s' already in use.\n'", name.c_str());
		assert(false && "model key already used");
	}
	else {
		storageMap[name] = new Model(premade);
		DebugMsg::out("model Manager: model '%s' loaded.\n'", name.c_str());
	}
}

Model* ModelManager::privGet(string name) {
	StorageMap::iterator it = storageMap.find(name);

	if (it == storageMap.end()) {
		DebugMsg::out("ERROR model Manager: Unknown model key '%s'.\n'", name.c_str());
		assert(false && "Unknown model key");
	}
	return storageMap[name];
}

void ModelManager::Terminate() {
	delete ptrInstance;
	ptrInstance = nullptr;
}
