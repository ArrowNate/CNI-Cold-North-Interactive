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
	//Filename will need the folder path as well "Assets/Texture/"
	// 
	//The floats are where we are positioning the texture starting with
	// p1x, p1y, meaning Point 1 x, Point 1 y.
	// it ranges from 0.0 to 1.0.
	// 
	//We will try to make a position function like in mario
	// make sure your image has a square dimention or else it will be wonky, ex 512 x 512.
	// 
	// keep the whole filename + folders under 50 characters
	// 
	// for channel it is for the file type:
	// GL_RGB = jpg
	// GL_RGBA = png
	Texture(const char filename[50], float p1x, float p1y, float p2x, float p2y, GLint channel);
	~Texture();

	void Draw();
};

#endif // !TEXTURE_H