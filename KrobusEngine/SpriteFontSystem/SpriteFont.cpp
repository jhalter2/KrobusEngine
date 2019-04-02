#include "SpriteFont.h"
#include "AzulCore.h"
#include "KrobusSprite.h"
#include "ImageManager.h"
#include "TextureManager.h"

SpriteFont::SpriteFont(std::string path) {
	FontTexture = TextureManager::Get("fontTex");
	XMLtoCollection(path);
}

SpriteFont::~SpriteFont() {
	for (FontMap::iterator it = fontmap.begin(); it != fontmap.end(); it++)
	{
		delete it->second;
	}
	DebugMsg::out("spritefont glyphs deleted\n");
}

void SpriteFont::CreateGlyph(rapidxml::xml_node<char>* node) {
	rapidxml::xml_node<char>* keynode = node;
	Key key = atoi(keynode->first_attribute()->value());

	keynode = keynode->first_node();
	float x = (float)atoi(keynode->value());
	keynode = keynode->next_sibling();
	float y = (float)atoi(keynode->value());
	keynode = keynode->next_sibling();
	float w = (float)atoi(keynode->value());
	keynode = keynode->next_sibling();
	float h = (float)atoi(keynode->value());

	Image *img = ImageManager::Load(Name + std::to_string(key),
		FontTexture, new Rect(x, y, w, h));
	fontmap[key] = new Glyph(img);
}

void SpriteFont::XMLtoCollection(std::string path) {
	rapidxml::file<char> FontData(path.c_str());

	using namespace rapidxml;
	xml_document<> doc;
	doc.parse<0>(FontData.data());

	xml_node<>* node = doc.first_node();
	while (node != nullptr)
	{
		if (strcmp(node->name(), "fontMetrics") == 0)
		{
			DebugMsg::out("SpriteFont: font data start for %s\n",
			node->first_attribute()->value());
			node = node->first_node();
		}
		else if (strcmp(node->name(), "character") == 0)
		{
			DebugMsg::out("SpriteFont: char data found\n");
			CreateGlyph(node);
			node = node->next_sibling();
		}
	}
}

SpriteFont::Glyph* SpriteFont::GetGlyph(char c) {
	FontMap::iterator it = fontmap.find(c);

	if (it == fontmap.end()) {
		DebugMsg::out("ERROR sprite font: Unknown char key '%s'.\n'", c);
		assert(false && "Unknown char key");
	}
	return it->second;
}
