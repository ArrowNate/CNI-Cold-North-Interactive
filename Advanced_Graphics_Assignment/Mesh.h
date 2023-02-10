#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <vector>

#include "Shader.h"



struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
	glm::vec3 Tangent;
	glm::vec3 Bitangents;
};

struct Texture3D {
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh
{
private:
	std::vector<Vertex> vertices; // vertices will hold the Position, Normal, TexCoords. Use . (dot notation)
	std::vector<unsigned int> indices;
	std::vector<Texture3D> textures;
	unsigned int VAO, VBO, EBO;

public:
	Mesh(std::vector<Vertex> _vertices, std::vector<unsigned int> _indices, std::vector<Texture3D> _textures);
	void Draw(Shader& shader);

private:

	void SetupMesh();
};

#endif