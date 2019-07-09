#ifndef _ModelManager
#define _ModelManager

#include <string>
#include <map>
#include "Model.h"

class ModelManager {

private:
	static ModelManager* ptrInstance;

	ModelManager() = default;
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator=(const ModelManager&) = delete;
	~ModelManager();

	static ModelManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ModelManager;
		return *ptrInstance;
	};

	friend class ModelManagerAttorney;

	typedef std::string string;
	typedef std::map<string, Model*> StorageMap;
	void privLoad(string name, string model);
	void privLoad(string name, Model::PreMadeModels premade);
	Model* privGet(string name);

	StorageMap storageMap;

	static void Terminate();

public:
	static const string DefaultPath;
	static const string Axis;
	static const string Plane;
	static const string Frigate;
	static const string Cottage;
	static const string Tank;
	static const string Missile;
	static const string BoundingSphere;
	static const string BoundingBox;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ModelManager::Load(string name, string model)
	///
	/// \brief	Loads a model
	///
	/// Method called in KrobusEngine::LoadResources() for loading a model. The default models provided are:
	/// -Axis;
	///	-Plane;
	///	-Frigate;
	///	-Cottage;
	///	-Player;
	///	-Enemy;
	///	
	///	The default path for loading other models is within the "Models/" folder
	///	
	///	  EXAMPLE:
	/// \code
	/// 	 KrobusEngine::LoadResources(){
	/// 		//loading my default player model
	/// 		ModelManager::Load("modelTank", ModelManager::Player);
	/// 		//can also load a list of default models
	/// 		ModelManager::Load("sphere", Model::PreMadedeModels::UnitSphere);
	/// 	 }
	/// \endcode
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name 	The name.
	/// \param	model	The model.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(string name, string model) { Instance().privLoad(name, model); };
	static void Load(string name, Model::PreMadeModels premade) { Instance().privLoad(name, premade); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Model* ModelManager::Get(string name)
	///
	/// \brief	Gets a model* using the given name
	///
	/// returns a pointer to a model that must have been already loaded in KrobusEngine::Loadresources().
	/// 
	///  \code
	/// 	 Player::Player(){
	/// 		//grabbing my loaded player model and setting the collision model
	/// 		Model* playerModel = ModelManager::Get("playerModel");
	/// 		SetColliderModel(playerModel);
	/// 	 }
	/// \endcode
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name to get.
	///
	/// \returns	Null if it fails, else a pointer to a Model.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Model* Get(string name) { return Instance().privGet(name); };
};

#endif _ModelManager


