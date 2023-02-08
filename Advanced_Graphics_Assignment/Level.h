#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "HUD.h"
#include "stb_image.h" // This library should allow us to load the level files we need.

class Level{
private:
	Font* m_pFont;
	HUD* m_pHUD;

public:

	Level();
	~Level();
	
	void Update();
	void Render();

};

#endif // !_LEVEL_H

//class Level {
//public:
//    Level(); // Not sure if this one is required or needed over the other one below**
//    Level(const std::string& filename);
//    ~Level();
//
//    void Load(const std::string& filename);
//    void Render();
//    void Update();
//
//    // Wasn't sure if we need the stuff below for textures and such. I was reading about it and though I should add it just in case. 
//private:
//    int width;
//    int height;
//    int channels; // I believe Richard said this can be used to determine the format and properties of the image, such as RGB and how to process the picture?
//    unsigned char* data; // This should handle the color values using the data pointer. The contents of the data array can then pass an image to a library like the stb_image.h to display a texture on the screen. I believe we need this to display the PNG or level on the screen?
//
//    std::vector<unsigned char*> textures; //This will let us store the pixel data of an image. We will use this to generate textures into graphics. Can store multiple textures that we can use as needed.
//};

