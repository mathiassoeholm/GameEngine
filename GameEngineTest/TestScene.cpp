#include "TestScene.h"
#include "../GameEngine/Material.h"
#include "../GameEngine/Mesh.h"
#include "../GameEngine/Primitives.h"
#include "../GameEngine/MeshRenderer.h"
#include "../GameEngine/Lighting/Light.h"
#include "CustomComponent.h"
#include "../GameEngine/Lighting/DirectionalLight.h"
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
	auto material = std::make_shared<Material>(readFile("Shaders/TexturedShader.vert"), readFile("Shaders/TexturedShader.frag"));
	material->assignTexture(std::make_shared<Texture>("Images/gaben.jpg"));

	auto cubeMesh = Primitives::createCube();
	auto cubeGO = instantiateGameObject();

	cubeGO->addComponent(new MeshRenderer(cubeMesh, material));
	cubeGO->addComponent(new CustomComponent());

	auto lightGo = instantiateGameObject();
    auto dirLight = new DirectionalLight(glm::vec3(1,-0.5, 0), glm::vec3(0.5, 0.5, 0.5));
    lightGo->addComponent(dirLight);

	// Create secondary cube go, with same mesh
	cubeGO = instantiateGameObject();
	cubeGO->addComponent(new MeshRenderer(cubeMesh, material));
}