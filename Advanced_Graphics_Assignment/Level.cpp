#include "Level.h"
#include <iostream>

//Level::Level(const std::string& filename) {
//	// This should hold the file names of the levels if there are multiple.
//}

Level::Level() {

	m_pHUD = new HUD();
}

Level::~Level() {

	delete m_pHUD;
	m_pHUD = nullptr;
}

void Level::Update()
{
}

void Level::Render() {

	m_pHUD->Draw();
}

//Level::Level() {}
//
//Level::Level(const std::string& filename) {
//    Load(filename);
//}
//
//Level::~Level() {
//    stbi_image_free(data); // This will free the memory currently taken up by an image we already loaded into memory. (data) is a pointer to the image data of the                         image. Ask Richard if this is the right path.**
//    for (auto& texture : textures) {
//        stbi_image_free(texture); // This will free the memory occupied by the image stored in the texture pointer. This should help us avoid memory leaks.
//    }
//}
//// This function should allow us to use the console for debugging if our data does not load properly for some reason.
//void Level::Load(const std::string& filename) {
//    data = stbi_load(filename.c_str(), &width, &height, &channels, 0); // This line is located in the stb_image.h: float *data = stbi_loadf(filename, &x, &y, &n,                                                                      0); width = x, height = y, channels = n, 0 is transparancy. I will write it as the words.
//    if (!data) {
//        std::cerr << "Failed to load level data from " << filename << std::endl;
//        return;
//    }
//
//    // This for statement should be responsible for loading textures from the level data. Richard used a for statement in the Mesh::Draw function in the example in class. Not sure if I should use this or if it is the same. This was done a bit differently. Also, this is like we did in Mario sort of, i is the column and j is the row. From doing research, the stbi_load_from_memory should load the image data into an array. Then back to textures vector I think. I have to research this more. **
//
//    /*for (int i = 0; i < width; i++) {
//        for (int j = 0; j < height; j++) {
//            int offset = (j * width + i) * channels;
//            unsigned char* textureData = (data + offset, channels, &width, &height, &channels, 0);
//            textures.push_back(textureData);
//        }
//    }*/
//}
//
//void Level::Render() {
//    // This should render the level textures
//    for (auto& texture : textures) {
//        // We will place all the render information here such as map, textures and stuff like that.
//    }
//
//    
//}
//
//void Level::Update() {
//    // Here we will update things such as camera and player position and such.
//}
