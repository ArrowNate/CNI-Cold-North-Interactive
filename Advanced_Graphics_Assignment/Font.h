#ifndef FONT_H
#define FONT_H

#include "Shader.h"

#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H

struct Character {
	unsigned int TextureID;  // ID handle of the glyph texture
	glm::ivec2   Size;       // Size of glyph
	glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
	unsigned int Advance;    // Offset to advance to next glyph
};



class Font {
private:	



public:
	void RenderText(Shader& shader, std::string text, float x, float y, float scale, glm::vec3 color);

	Font(std::string text, std::string fontPath, int size, glm::vec3 color);
	
	
	

	Font();
	~Font();
};

#endif // !FONT_H