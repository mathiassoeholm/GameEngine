#pragma once

#include "Matrix4x4.h"
#include "Vector4.h"
#include "Quaternion.h"
#include <GLFW/glfw3.h>

using namespace Math_ias;

class Camera
{
	GLFWwindow* _window;
	Matrix4x4f _projMatrix;
	Matrix4x4f _viewMatrix;
	Vector3f _position;
	Quaternionf _rotation;
	
	void calculateViewMatrix();
public:
	Camera(GLFWwindow* window, Vector3f position, Quaternionf rotation);
	Matrix4x4f getProjMatrix() const;
	Matrix4x4f getViewMatrix() const;
	void calculateProjMatrix();
	void setPosition(Vector3f position);
	void setRotationn(Quaternionf rotation);
};

