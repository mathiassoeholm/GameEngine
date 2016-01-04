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
	Matrix4x4f _inverseProjMatrix;
	Matrix4x4f _viewMatrix;
	Matrix4x4f _inverseViewMatrix;
	Vector3f _position;
	Quaternionf _rotation;
	
	void calculateViewMatrix();
public:
	Camera(GLFWwindow* window, Vector3f position, Quaternionf rotation);
	Matrix4x4f getProjMatrix() const;
	Matrix4x4f getViewMatrix() const;
	void calculateProjMatrix();
	void setPosition(Vector3f position);
	void setRotation(Quaternionf rotation);
	Vector3f getPosition() const;
	Quaternionf getRotation() const;

	// Returns a ray going from the camera to
	// the mouse's positioin in world space
	Vector3f mouseRay() const;
};

