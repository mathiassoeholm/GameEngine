#include "TestScene.h"
#include "../GameEngine/Material.h"
#include "../GameEngine/Mesh.h"
#include "../GameEngine/Primitives.h"
#include "../GameEngine/MeshRenderer.h"
#include "../GameEngine/Lighting/Light.h"
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
	Material material(readFile("Shaders/TexturedShader.vert"), readFile("Shaders/TexturedShader.frag"));
	material.assignTexture(std::make_shared<Texture>("Images/bricks.jpg"));

	Mesh cubeMesh = Primitives::createCube();
	auto cubeGO = instantiateGameObject();

	cubeGO->addComponent(new MeshRenderer(cubeMesh, material));
	cubeGO->addComponent(new CustomComponent());

	auto light = instantiateGameObject();
	light->addComponent(new Light());

	// Create secondary cube go, with same mesh
	//cubeGO = instantiateGameObject();
	//cubeGO->addComponent(new MeshRenderer(cubeMesh, material));
}