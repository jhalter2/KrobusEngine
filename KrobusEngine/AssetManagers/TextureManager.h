#ifndef _TextureManager
#define _TextureManager

#include <string>
#include <map>

class Texture;
class TextureManager {

private:
	static TextureManager* ptrInstance;

	TextureManager() = default;
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	~TextureManager();

	static TextureManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TextureManager;
		return *ptrInstance;
	};

	friend class TextureManagerAttorney;

	typedef std::string string;
	typedef std::map<string, Texture*> StorageMap;
	void privLoad(string name, string texture);
	void privLoad(string name, unsigned char r, unsigned char g, unsigned char b);
	Texture* privGet(string name);

	StorageMap storageMap;

	static void Terminate();

public:
	static const string DefaultPath;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void TextureManager::Load(string name, string texture)
	///
	/// \brief	Loads a texture
	///
	/// This is the method used to load a texture. Textures should be image files in the .tga format.
	/// The default file path for textures is "Texture/" but this will be automatically included when loading. 
	/// All asset loading should be done in the KrobusEngine::LoadResources() function.
	/// 
	///  EXAMPLE:
	/// \code
	/// 	 KrobusEngine::LoadResources(){
	/// 		TextureManager::Load("terrainTexture", "ground.tga");
	/// 		groundTexture = TextureManager::Get("terrainTexture");
	/// 	 }
	/// \endcode
	/// 		
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name   	The name.
	/// \param	texture	The texture.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(string name, string texture) { Instance().privLoad(name, texture); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void TextureManager::Load(string name, string texture)
	///
	/// \brief	Loads a texture
	///
	/// This is the method used to load a single pixel texture. Add in the rgb values after the texture name
	/// All asset loading should be done in the KrobusEngine::LoadResources() function.
	/// 
	///  EXAMPLE:
	/// \code
	/// 	 KrobusEngine::LoadResources(){
	/// 		//gets a white texture
	/// 		TextureManager::Load("terrainTexture", 1.0f, 1.0f, 1.0f);
	/// 		groundTexture = TextureManager::Get("terrainTexture");
	/// 	 }
	/// \endcode
	/// 		
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name   	The name.
	/// \param	texture	The texture.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void Load(string name, unsigned char r, unsigned char g, unsigned char b) { Instance().privLoad(name, r, g, b); };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Texture* TextureManager::Get(string name)
	///
	/// \brief	Gets a texture* using the given name
	///
	/// Search by name for a texture that has already been loaded into the texture manager.
	/// Returns a pointer to the texture.
	/// 
	/// \code
	/// 	 Player::Player(){
	/// 		Texture* playerTexture = TextureManager::Get("playerTexture");
	/// 	 }
	/// \endcode
	/// 		
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name to get.
	///
	/// \returns	Null if it fails, else a pointer to a Texture.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Texture* Get(string name) { return Instance().privGet(name); };
};

#endif
