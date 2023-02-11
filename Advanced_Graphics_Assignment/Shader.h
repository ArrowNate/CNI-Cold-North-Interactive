#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
class Shader  
{
public:
	//the program iD
	unsigned int ID;

	//Constructor
	Shader(const char* vertexPath, const char* fragmentPath);
	Shader();

	
	~Shader();

	// use /activate the shader
	void Use();
	void Vector3(const char* name, const glm::vec3& value);  // vector3 or vec3?
	void SetBool(const std::string& name, bool value) const; // std::string& = pasing the memory address of the variable
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMat4(const std::string& name, glm::mat4& value) const;
	void SetID(unsigned int id);
	unsigned int GetID();



};

#endif // !SHADER_H