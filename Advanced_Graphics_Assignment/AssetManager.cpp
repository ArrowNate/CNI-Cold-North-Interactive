#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager* AssetManager::Instance()
{
	if (sInstance == nullptr) {
		sInstance = new AssetManager();
	}

	return sInstance;
}

void AssetManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

AssetManager::~AssetManager()
{
	
}

AssetManager::AssetManager() 
{

}

Texture* AssetManager::GetTexture(std::string filename) {
	std::string fullPath;

	if (m_pTextures[fullPath] == nullptr) {
		m_pTextures[fullPath] = Texture::Instance()->LoadTexture(fullPath);
	}

	if (m_pTextures[fullPath] != nullptr) {
		m_pTextureRefCount[m_pTextures[fullPath]] += 1;
	}

	return m_pTextures[fullPath];
}