#ifndef _KrobusSprite
#define _KrobusSprite

#include <string>

class GraphicsObject_Sprite;
class Camera;
class Image;

class KrobusSprite {
public:
	KrobusSprite() = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	KrobusSprite::KrobusSprite(std::string imgKey);
	///
	/// \brief	sprite constructor
	/// 		
	/// a KrobusSprite is a 2D image that will be render onto the 2D camera. Sprites can either be constructed by
	/// image key (loaded into assets) or by image pointer. The sprite has multiple methods for customizing the size
	/// and scale of the image as well as where to render it		
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	imgKey	The image key.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	KrobusSprite(std::string imgKey);
	KrobusSprite(Image* pImg);
	KrobusSprite(const KrobusSprite&) = delete;
	KrobusSprite& operator=(const KrobusSprite&) = delete;
	~KrobusSprite();

	void Render(Camera* pCam);
	void UpdateWorld();
	float GetAngle();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KrobusSprite::SetAngle(float a);
	///
	/// \brief	Sets a sprite angle
	///
	/// which angle the sprite image will be rotated at
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	a	A float to process.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetAngle(float a);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KrobusSprite::SetCenter(float offsetx, float offsety);
	///
	/// \brief	Sets a center
	///
	/// control the center point of the sprite image to be rendered
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	offsetx	The offsetx.
	/// \param	offsety	The offsety.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetCenter(float offsetx, float offsety);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KrobusSprite::SetPosition(float x, float y);
	///
	/// \brief	Sets a position
	///
	/// set the position of the sprite, starting from its center
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	x	The x coordinate.
	/// \param	y	The y coordinate.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetPosition(float x, float y);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KrobusSprite::SetScaleFactor(float scalex, float scaley);
	///
	/// \brief	Sets scale factor
	///
	/// scales up the sprite by a scalar value
	/// 
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	scalex	The scalex.
	/// \param	scaley	The scaley.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetScaleFactor(float scalex, float scaley);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void KrobusSprite::SetScalePixel(float width, float height);
	///
	/// \brief	Sets scale pixel
	///
	/// scales up the sprite by specific pixel sizes
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param	width 	The width.
	/// \param	height	The height.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetScalePixel(float width, float height);
	float GetSpriteWidth();
	float GetSpriteHeight();
private:
	GraphicsObject_Sprite* pGOSprite;
	float angle;
	float centerX;
	float centerY;
	float scaleX;
	float scaleY;
};

#endif _KrobusSprite
