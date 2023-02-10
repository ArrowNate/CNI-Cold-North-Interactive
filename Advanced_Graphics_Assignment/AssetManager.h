#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include "Shader.h"
#include "Texture.h"
#include <map>
#include <sstream>

class AssetManager
{
private:
	std::map<std::string, Texture*> m_pTextures;
	//std::map<std::string, TTF_Font*> m_pFonts;

	std::map<Texture*, unsigned> m_pTextureRefCount;

public:
	static AssetManager* Instance();
	static AssetManager* sInstance;
	static void Release();

	Texture* GetTexture(std::string filename);

private:
	AssetManager();
	~AssetManager();
};

#endif