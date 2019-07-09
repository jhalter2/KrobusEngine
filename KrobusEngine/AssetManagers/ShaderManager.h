#ifndef _ShaderManager
#define _ShaderManager

#include <string>
#include <map>
#include "SHADER_TYPES.h"

class ShaderMultiPointlight;
class ShaderColorLight;
class ShaderTexture;

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
	typedef std::map<string, ShaderMultiPointlight*> TextureStorageMap;
	TextureStorageMap texStorageMap;

	typedef std::map<string, ShaderColorLight*> ColorStorageMap;
	ColorStorageMap colStorageMap;

	typedef std::map<string, ShaderTexture*> TexStorageMap;
	TexStorageMap textureStorageMap;

	void privLoad(string name, SHADER_TYPES render);
	ShaderMultiPointlight* privGetTextureShader(string name);
	ShaderColorLight* privGetColorShader(string name);
	ShaderTexture* privGetTexShader(string name);

	static void Terminate();

public:
	static const string DefaultPath;
	static const string TextureLight;
	static const string ColorLight;
	static const string Texture;

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

	static void Load(string name, SHADER_TYPES render) { Instance().privLoad(name, render); };

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

	static ShaderMultiPointlight* GetTextureShader(string name) { return Instance().privGetTextureShader(name); };
	static ShaderColorLight* GetColorShader(string name) { return Instance().privGetColorShader(name); };
	static ShaderTexture* GetTexShader(string name) { return Instance().privGetTexShader(name); };
};

#endif _ShaderManager
