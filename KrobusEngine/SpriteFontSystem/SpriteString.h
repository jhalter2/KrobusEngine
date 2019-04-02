#ifndef _SpriteString
#define _SpriteString

#include <string>
#include <list>

class SpriteFont;
class KrobusSprite;
class Camera;

class SpriteString {
public:
	SpriteString() = default;
	SpriteString(const SpriteFont&) = delete;
	SpriteString(const SpriteString&) = delete;
	SpriteString& operator=(const SpriteString&) = delete;
	SpriteString(SpriteFont* sf, std::string s, int x, int y);
	~SpriteString() = default;

	using Glyph = KrobusSprite;
	//collection of glyphs that make up the string
	using GlyphCollection = std::list <Glyph*>;
	void Render();
	int GetWidth();
	int GetHeight();
	void Set(int x, int y);
	void Set(SpriteFont* sf, std::string s, int x, int y);

private:
	GlyphCollection glyphs;
	SpriteFont *sfont;
	int width;
	int height;
	int posx;
	int posy;
	const float DEFAULT_SCALE = 0.5f;
};

#endif _SpriteString
