#ifndef _ImageManager
#define _ImageManager

#include <string>
#include <map>
#include "AzulCore.h"

class Texture;
class Image;

class ImageManager {
private:
	static ImageManager* ptrInstance;

	ImageManager() = default;
	ImageManager(const ImageManager&) = delete;
	ImageManager& operator=(const ImageManager&) = delete;
	~ImageManager();

	static ImageManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ImageManager;
		return *ptrInstance;
	};

	friend class ImageManagerAttorney;

	typedef std::string string;
	typedef std::map<string, Image*> StorageMap;
	StorageMap storageMap;

	Image* privLoad(string name, Texture* tex);
	Image* privLoad(string name, Texture* tex, Rect* r);
	Image* privGet(string name);

	static void Terminate();

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Image* ImageManager::Load(string name, Texture* tex)
	///
	/// \brief	Loads images
	///
	/// used for loading sprite images, mapping a name to a texture (image)
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param 		   	name	The name.
	/// \param [in,out]	tex 	If non-null, the tex.
	///
	/// \returns	Null if it fails, else a pointer to an Image.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Image* Load(string name, Texture* tex) { return Instance().privLoad(name, tex); }
	static Image* Load(string name, Texture* tex, Rect* r) { return Instance().privLoad(name, tex, r); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static Image* ImageManager::Get(string name)
	///
	/// \brief	Gets an image* using the given name
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	name	The name to get.
	///
	/// \returns	Null if it fails, else a pointer to an Image.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Image* Get(string name) { return Instance().privGet(name); }
};

#endif _ImageManager
