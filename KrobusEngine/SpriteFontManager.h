#ifndef _SpriteFontManager
#define _SpriteFontManager

#include <string>
#include <map>

class SpriteFont;

class SpriteFontManager {
private:
	static SpriteFontManager* ptrInstance;

	SpriteFontManager() = default;
	SpriteFontManager(const SpriteFontManager&) = delete;
	SpriteFontManager& operator=(const SpriteFontManager&) = delete;
	~SpriteFontManager();

	static SpriteFontManager& Instance() {
		if (!ptrInstance)
			ptrInstance = new SpriteFontManager;
		return *ptrInstance;
	};

	friend class SpriteFontManagerAttorney;

	typedef std::string string;
	typedef std::map<string, SpriteFont*> StorageMap;

	void privLoad(string name, string path);
	SpriteFont* privGet(string name);

	StorageMap storageMap;

	static void Terminate();

public:
	static const string DefaultPath;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void SpriteFontManager::Load(string name, string path)
	///
	/// \brief	Loads
	/// 		
	/// Loads a sprite sheet based on input file. Default file path is in Fonts/.
	/// 
	/// \code
	/// 	 KrobusEngine::LoadResources(){
	/// 		//load my font sheet
	/// 		TextureManager::Load("fontTex", "FontSheet.tga");
	/// 		//fontXML is the data sheet created when parsing the html file using RapidXML
	///			SpriteFontManager::Load("font1", "FontXML.xml");
	/// 	 }
	/// \endcode
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name.
	/// \param	path	Full pathname of the file.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(string name, string path) { Instance().privLoad(name, path); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static SpriteFont* SpriteFontManager::Get(string name)
	///
	/// \brief	Gets a sprite font* using the given name
	///
	/// returns the spritefont loaded already loaded in		 		
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name to get.
	///
	/// \returns	Null if it fails, else a pointer to a SpriteFont.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static SpriteFont* Get(string name) { return Instance().privGet(name); }
};

#endif _SpriteFontManager
