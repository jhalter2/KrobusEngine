#ifndef _SpriteFont
#define _SpriteFont

#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"
#include <string>
#include <map>

class Texture;
class KrobusSprite;

class SpriteFont {
public:
	using Key = int;
	using Glyph = KrobusSprite;

private:
	Texture* FontTexture;
	using FontMap = std::map<Key, Glyph*>;
	FontMap fontmap;
	std::string Name;

	void CreateGlyph(rapidxml::xml_node<char>* node);
	void XMLtoCollection(std::string path);

public:
	SpriteFont() = delete;
	SpriteFont(std::string path);
	SpriteFont(const SpriteFont&) = delete;
	SpriteFont& operator=(const SpriteFont&) = delete;
	~SpriteFont();

	Glyph* GetGlyph(char c);
};

#endif _SpriteFont
