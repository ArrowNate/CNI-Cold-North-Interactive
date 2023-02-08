#ifndef FONT_H
#define FONT_H
#include "Shader.h"
#include <map>
#include <ft2build.h>
#include <unordered_map>
#include "HUD.h"
#include FT_FREETYPE_H // This is a library for rendering text on screen. 

struct Character {
	unsigned int TextureID;  // ID handle of the glyph texture
	glm::ivec2   Size;       // Size of glyph
	glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
	unsigned int Advance;    // Offset to advance to next glyph
};

class Font {
private:

	std::map<GLchar, Character> Characters;
	unsigned int VBO, VAO;
	Shader ourShader;

public:

	void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);

	Font();
	~Font();
};

#endif // !FONT_H