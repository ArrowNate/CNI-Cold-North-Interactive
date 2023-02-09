#ifndef TEXTURE_H
#define TEXTURE_H
#include "GameEntity.h"
#include "Shader.h"
#include "stb_image.h"


class Texture : public GameEntity
{
private:
	unsigned int texture;
	unsigned int VBO, VAO, EBO;


public:
	
	Texture(const char filename[50], float p1x, float p1y, float p2x, float p2y, GLint channel); // From class.
	~Texture();

	void Draw();
};

#endif // !TEXTURE_H