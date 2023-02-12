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
	static Texture* Instance();
	Texture* LoadTexture(std::string path);
	
	Texture(const char filename[50], float p1x, float p1y, float p2x, float p2y, GLint channel);
	~Texture();

	void Draw();
};

#endif // !TEXTURE_H