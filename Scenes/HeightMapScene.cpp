#include "HeightMapScene.h"

void HeightMapScene::init(GLFWwindow *window, int screenWidth, int screenHeight)
{
	const int SEGMENTS = 100;

	camera = Camera(window, Vector3f(), Quaternionf());
	GLfloat vertices[SEGMENTS * SEGMENTS * 5];



	// Load image
	// Generate vertices
}

void HeightMapScene::run(GLFWwindow *window)
{

}
