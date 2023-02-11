#ifndef MODEL_H
#define MODEL_H

#include <glad/glad.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.h"
#include "GameEntity.h"
    
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

class Model : public GameEntity
{
private:
    std::vector<Mesh> meshes;
    std::string directory;
    std::vector<Texture3D> texturesLoaded;

    Shader modelShader;

public:
    Model(std::string const& path);
    void Draw(Shader& shader);
    unsigned int TextureFromFile(const char* path, const std::string& directory);

private:
    void LoadModel(std::string path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture3D> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);



public:
    void ModelTranslate(float x , float y, float z);
    void ModelScale(float x , float y, float z);

    void Render(glm::mat4 modelName);
};

#endif // ! MODEL_H