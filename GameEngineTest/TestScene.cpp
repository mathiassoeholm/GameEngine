#include "TestScene.h"
#include "../GameEngine/Material.h"
#include "../GameEngine/Mesh.h"
#include "../GameEngine/Primitives.h"
#include "../GameEngine/MeshRenderer.h"
#include "CustomComponent.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& fileName)
{
	std::ifstream t(fileName);
	std::stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

void TestScene::initialize()
{
	Material material(readFile("Shaders/BasicVertexShader.vert"), readFile("Shaders/BasicFragmentShader.frag"));
	Mesh cubeMesh = Primitives::createCube();
	auto cubeGO = instantiateGameObject();

	cubeGO->addComponent(new MeshRenderer(cubeMesh, material));
	cubeGO->addComponent(new CustomComponent());

	// Create secondary cube go, with same mesh
	//cubeGO = instantiateGameObject();
	//cubeGO->addComponent(new MeshRenderer(cubeMesh, material));
}
