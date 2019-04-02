#ifndef _ScreenLog
#define _ScreenLog

#include "SpriteString.h"
#include "SpriteFontManager.h"

#include <string>
#include <list>

class SpriteFont;

class ScreenLog {
private:
	static ScreenLog* ptrInstance;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	ScreenLog::ScreenLog() = default;
	///
	/// \brief	Default constructor
	///
	/// the screen log is a way for text and data to be rendered onto the screen as a spritestring
	/// it offers control over the position, font used, and what kind of data to be displayed
	/// \author	jehalter
	/// \date	3/17/2019
	////////////////////////////////////////////////////////////////////////////////////////////////////

	ScreenLog() = default;
	ScreenLog(const ScreenLog&) = delete;
	ScreenLog& operator=(const ScreenLog&) = delete;
	~ScreenLog();

	static ScreenLog& Instance()
	{
		if (!ptrInstance) {
			ptrInstance = new ScreenLog;
			ptrInstance->pSS = new SpriteString();
			ptrInstance->font = SpriteFontManager::Get("font1");
		}
		return *ptrInstance;
	};

	friend class ScreenLogAttorney;

	static void Render();
	static void Terminate();

	SpriteFont* font;
	SpriteString* pSS;
	int anchorX;
	int anchorY;
	char DebugBuff[256];
	using MessageCollection = std::list <std::string>;
	MessageCollection messages;

	int count = 1;
	int DEFAULT_POS_X = 50;
	int DEFAULT_POS_Y = 550;
	int Y_SPACING = 40;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	static void ScreenLog::Add(char* A, ...);
	///
	/// \brief	Adds text to the spritestring
	///
	/// The way to add text to the log to be displayed is through its Add() method. 
	/// The Add() method allows data to be added and then rendered through printf style formatting
	/// An example of this would be
	/// 
	/// \code
	///		float playerPosition = 10;
	///		ScreenLog::Add("Player Position %1.0f\n", playerPosition);
	///\endcode
	///
	/// \author	jehalter
	/// \date	3/17/2019
	///
	/// \param [in,out]	A  	If non-null, a char to process.
	/// \param 		   	...	Variable arguments providing additional information.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Add(char* A, ...);
};

#endif _ScreenLog
