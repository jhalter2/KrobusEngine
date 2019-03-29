#ifndef _ShaderManager
#define _ShaderManager

#include <string>
#include <map>

class ShaderObject;
class ShaderManager {

private:
	static ShaderManager* ptrInstance;

	ShaderManager() = default;
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	~ShaderManager();				

	static ShaderManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ShaderManager;
		return *ptrInstance;
	};

	friend class ShaderManagerAttorney;

	typedef std::string string;
	typedef std::map<string, ShaderObject*> StorageMap;
	StorageMap storageMap;

	void privLoad(string name, string render);
	ShaderObject* privGet(string name);

	static void Terminate();

public:
	static const string DefaultPath;
	static const string Texture;
	static const string TextureLight;
	static const string ColorConstant;
	static const string Color;
	static const string ColorLight;
	static const string VaryColor;
	static const string ColorByPosition;
	static const string Sprite;
	static const string SpriteLine;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ShaderManager::Load(string name, string render)
	///
	/// \brief	Loads shader
	///
	/// Loads whichever shader is needed. Default shaders available are:
	/// 
	///	-Texture;
	///	-TextureLight;
	///	-ColorConstant;
	///	-Color;
	///	-ColorLight;
	///	-VaryColor;
	///	-ColorByPosition;
	///	-Sprite;
	///	-SpriteLine;
	///	
	///	The default filepath for outside shaders is the "Shaders/" folder
	///	Whichever shaders are needed should be loaded in KrobusEngine::LoadResources() and can be
	///	accessed through static use
	///	
	///	  \code
	/// 	KrobusEngine::LoadResources(){
	/// 		//loading a shader for my player object which will use a texture and have light
	/// 		ShaderManager::Load("playerShader", ShaderManager::TextureLight);
	/// 	}
	///	\endcode
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name  	The name.
	/// \param	render	The render.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(string name, string render) { Instance().privLoad(name, render); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static ShaderObject* ShaderManager::Get(string name)
	///
	/// \brief	Gets a shader object* using the given name
	///
	/// Returns a shader that has been loaded into the shadermanager in LoadResources()
	///	\code
	/// 	Building::Building(){
	/// 		//getting the light texture I loaded for my building
	/// 		ShaderObject* pShader = ShaderManager::Get("buildingShader");
	/// 	}
	///	\endcode
	///			
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name to get.
	///
	/// \returns	Null if it fails, else a pointer to a ShaderObject.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static ShaderObject* Get(string name) { return Instance().privGet(name); };
};

#endif
