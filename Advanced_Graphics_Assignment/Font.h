#pragma once
#include "GameEntity.h"
#include "Shader.h"

#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H

class Font :  public GameEntity
{
private:	

	int mWidth;
	int mHeight;

	

public:
	void RenderText(Shader& shader, std::string text, float x, float y, float scale, glm::vec3 color);

	Font(std::string text, std::string fontPath, int size, Vector3 color);
	
	Font();
	~Font();
};

