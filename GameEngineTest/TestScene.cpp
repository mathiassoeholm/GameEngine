#include "TestScene.h"
#include "../GameEngine/Material.h"
#include "../GameEngine/Mesh.h"
#include "../GameEngine/Primitives.h"
#include "../GameEngine/MeshRenderer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

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
	Mesh triangleMesh = Primitives::createTriangle();
	GameObject triangleGo;

	triangleGo.addComponent(new MeshRenderer(triangleMesh, material));

	addGameObject(triangleGo);
}
