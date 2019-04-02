#include "SpriteString.h"
#include "KrobusSprite.h"
#include "SpriteFont.h"
#include "AzulCore.h"
#include "ImageManager.h"
#include "Image.h"
#include "SceneManager.h"
#include "Scene.h"

SpriteString::SpriteString(SpriteFont* sf, std::string s, int x, int y) {
	sfont = sf;
	Set(x, y);
	Glyph* G;
	int count = 0;
	//for each char in the string, need to convert to int then to string
	//since that's how it's stored in the image manager
	//then make a glyph from the string and add it to the
	//glyphs collection
	for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
		G = sf->GetGlyph(s[count]);
		G->SetScaleFactor(0.5f, 0.5f);
		glyphs.push_back(G);
		count++;
	}
}

void SpriteString::Render() {
	float pos = float(posx);
	float incr = 0.0f;
	for (GlyphCollection::iterator it = glyphs.begin(); it != glyphs.end(); ++it) {
		incr = (*it)->GetSpriteWidth();
		pos += incr;
		(*it)->SetPosition(pos, float(posy));
		(*it)->Render(SceneManager::GetCurrentScene()->GetCurrent2DCamera());
	}
	glyphs.clear();
}

int SpriteString::GetWidth() {
	return width;
}

int SpriteString::GetHeight() {
	return height;
}

void SpriteString::Set(int x, int y) {
	posx = x;
	posy = y;
}

void SpriteString::Set(SpriteFont* sf, std::string s, int x, int y) {
	sfont = sf;
	Set(x, y);
	Glyph* G;
	int count = 0;
	//for each char in the string, need to convert to int then to string
	//since that's how it's stored in the image manager
	//then make a glyph from the string and add it to the
	//glyphs collection
	for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
		G = sf->GetGlyph(s[count]);
		glyphs.push_back(G);
		count++;
	}
}
