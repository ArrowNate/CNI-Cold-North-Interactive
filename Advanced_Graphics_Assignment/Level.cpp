#include "Level.h"
#include <iostream>

Level::Level() {}

Level::Level(const std::string& filename) {
    Load(filename);
}

Level::~Level() {
    stbi_image_free(data); // This will free the memory currently taken up by an image we already loaded into memory. (data) is a pointer to the image data of the image. Ask Richard if this is the right path.**
    for (auto& texture : textures) {
        stbi_image_free(texture); // This will free the memory occupied by the image stored in the texture pointer. This should help us avoid memory leaks.
    }
}
// This function should allow us to use the console for debugging if our data does not load properly for some reason.
void Level::Load(const std::string& filename) {
    data = stbi_load(filename.c_str(), &width, &height, &channels, 0); // This line is located in the stb_image.h: float *data = stbi_loadf(filename, &x, &y, &n, 0); width = x, height = y, channels = n, 0 is transparancy. I will write it as the words.
    if (!data) {
        std::cerr << "Failed to load level data from " << filename << std::endl;
        return;
    }

    // This for statement should be responsible for loading textures from the level data. Richard used a for statement in the Mesh::Draw function in the example in class. Not sure if I should use this or if it is the same. This was done a bit differently. Also, this is like we did in Mario sort of, i is the column and j is the row. From doing research, the stbi_load_from_memory should load the image data into an array. Then back to textures vector I think. I have to research this more. **
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int offset = (j * width + i) * channels;
            unsigned char* textureData = (data + offset, channels, &width, &height, &channels, 0);
            textures.push_back(textureData);
        }
    }
}

void Level::Render() {
    // This should render the level textures
    for (auto& texture : textures) {
        // We will place all the render information here such as map, textures and stuff like that.
    }
}

void Level::Update() {
    // Here we will update all the things such as camera and player position and such.
}

//////////////////////////////////////////////////////////////////////

// MARIO - LEVEL.CPP /// Only if we use XML maps this will be useless otherwise i believe.

//#include "Level.h"
//
//Level::Level() {}
//
//Level::Level(std::string filename) {
//    // load the level data from the specified file
//	//Reading and loading the data from the xml file
//	std::string fullPath = SDL_GetBasePath();
//	fullPath.append(filename);
//	mXMLDocument.LoadFile(fullPath.c_str());
//	mWidth = mXMLDocument.FirstChildElement("map")->FirstChildElement("layer")->IntAttribute("width");
//	mHeight = mXMLDocument.FirstChildElement("map")->FirstChildElement("layer")->IntAttribute("height");
//	auto element = mXMLDocument.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data");
//
//	mOffsetX = 32;
//	mOffsetY = 32;
//	mTile = 0;
//	mTileInfo = element->GetText(); //<---A string of the information between the data tag from the xml file.
//
//	for (int i = 0; i < mTileInfo.length(); i++) {
//		mLevel.push_back(mTileInfo[i]); //<-----pushing each element of the array mTileInfo into a vector
//	}
//
//	for (int i = 0; i < mHeight; i++) {
//		std::vector<char> levelWidth;
//		for (int j = 0; j <= mWidth * 2; j++) {
//			if (mLevel[mTile] != '\n' && mLevel[mTile] != ',') {
//				levelWidth.push_back(mLevel[mTile]); //<----Pushing each char into a column for debugging
//			}
//			mTile++;
//		}
//		mLevelHeight.push_back(levelWidth);//<----Pushing each column into a row for debugging
//	}
//
//	int x = 0;
//	int y = 0;
//
//	for (int i = 0; i < mLevelHeight.size(); i++) {
//		for (int j = 0; j < mWidth; j++) {
//			std::cout << mLevelHeight[i][j];
//			m_pLevelTextures.push_back(LevelTextures(mLevelHeight[i][j]));
//		}
//		std::cout << std::endl; //<-----Displaying the map into the console for debugging
//	}
//
//	//This for loop sets the position and scale of each tile in the m_pLevelTextures vector
//	mTile = 0;
//	for (int i = 0; i < m_pLevelTextures.size(); i++) {
//		if (m_pLevelTextures[mTile] != nullptr) {
//			m_pLevelTextures[mTile]->Scale(Vector2(2.0f, 2.0f));
//			m_pLevelTextures[mTile]->Position(x + 16, y + 183);
//			m_pLevelTextures[mTile]->Parent(this);
//		}
//		x += mOffsetX;
//		mTile++;
//		if (mTile % mWidth == 0) {
//			y += mOffsetY;
//			x = 0;
//		}
//	}
//	mTile = 0;
//	/*mLevel clear();
//	mLevelHeight clear();*/
//}
//  
//Level::~Level() {
//    // deallocate any resources that were allocated in the constructor
//
//}
//
//std::vector<Texture*> Level::GetLevelTextures() {
//    return m_pLevelTextures;
//}
//
//Texture* Level::LevelTextures(char c) {
//    // return the Texture associated with the specified character in the level data
//}
//
//void Level::Update() {
//    // update the level, for moving certain tiles or enemies and such
//}
//
//void Level::Render() {
//    // render the level, textures and such
//}

//////////////////////////////////////////////////////////////////////