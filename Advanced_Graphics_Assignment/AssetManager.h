#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include "Shader.h"
#include "Texture.h"

class AssetManager
{

public:
	static AssetManager* Instance();
	static AssetManager* sInstance;
	static void Release();

private:
	AssetManager();
	~AssetManager();
};

#endif