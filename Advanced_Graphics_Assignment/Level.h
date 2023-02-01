#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "stb_image.h" // This library should allow us to load the .PNG files we need. Richard said to make sure we use .PNG files

class Level {
public:
    Level();
    Level(const std::string& filename);
    ~Level();

    void Load(const std::string& filename);
    void Render();
    void Update();

private:
    int width;
    int height;
    int channels; // I believe Richard said this can be used to determine the format and properties of the image, such as RGB and how to process the picture?
    unsigned char* data; // This should handle the color values using the data pointer. The contents of the data array can then pass an image to a library like the stb_image.h to display a texture on the screen. I believe we need this to display the PNG on the screen.

    std::vector<unsigned char*> textures; //This will let us store the pixel data of an image. We will use this to generate textures into graphics. Can store multiple textures that we can use as needed.
};

#endif // !_LEVEL_H

//////////////////////////////////////////////////////////////////////

// MARIO - LEVEL.H /// Only if we use XML maps this will be useless otherwise i believe.

//#ifndef _LEVEL_H
//#define _LEVEL_H
//#include <vector>
//#include <string>
//#include "TextureGL.h"
//
//class Level {
//protected:
//
//	int mWidth;
//	int mHeight;
//	std::vector<std::vector<char>> mLevelHeight;
//	std::vector<char> mLevel;
//	std::vector<Texture*> m_pLevelTextures;
//
//	Texture* m_ptile;
//
//public:
//	std::vector<Texture*> GetLevelTextures;
//	Texture* LevelTextures(char);
//
//	void Update();
//	void Render();
//
//	Level();
//	Level(std::string); // This is a constructor for the level class. 
//	~Level();
//};
//#endif // !_LEVEL_H

//////////////////////////////////////////////////////////////////////
