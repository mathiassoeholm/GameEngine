#include "Camera.h"
#include <iostream>

#define ONE_DEG_IN_RAD 0.017444444

Camera::Camera(GLFWwindow* window, Vector3f position, Quaternionf rotation) : _window(window), _position(position), _rotation(rotation)
{
	calculateViewMatrix();
	calculateProjMatrix();
}

void Camera::calculateProjMatrix()
{
	int windowWidth, windowHeight;
	glfwGetWindowSize(_window, &windowWidth, &windowHeight);

	float near = 0.1f;
	float far = 100.0f;
	float fov = 67.0f * static_cast<float>(ONE_DEG_IN_RAD);
	float aspect = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);

	float range = tan(fov * 0.5f) * near;
	float Sx = (2.0f * near) / (range * aspect + range * aspect);
	float Sy = near / range;
	float Sz = -(far + near) / (far - near);
	float Pz = -(2.0f * far * near) / (far - near);

	_projMatrix = Matrix4x4f(
		Sx, 0, 0, 0,
		0, Sy, 0, 0,
		0, 0, Sz, Pz,
		0, 0, -1, 0);

	_inverseProjMatrix = Matrix4x4f(
		1/Sx, 0, 0, 0,
		0, 1/Sy, 0, 0,
		0, 0, 0, 1/-1,
		0, 0, 1/Pz, (-Sz)/(-Pz));
}

void Camera::setPosition(Vector3f position)
{
	_position = position;
	calculateViewMatrix();
}

void Camera::setRotation(Quaternionf rotation)
{
	_rotation = rotation;
	calculateViewMatrix();
}

Vector3f Camera::mouseRay() const
{
	double mouseX, mouseY;
	glfwGetCursorPos(_window, &mouseX, &mouseY);

	int windowWidth, windowHeight;
	glfwGetWindowSize(_window, &windowWidth, &windowHeight);

	// Get normalized device coordinates
	auto x = (2.0 * mouseX) / windowWidth - 1.0;
	auto y = 1.0 - (2.0 * mouseY) / windowHeight;

	// Get 4D Homogeneous Clip Coordinates
	auto rayClip = Vector4<float>(static_cast<float>(x), static_cast<float>(y), -1.0, 1.0);

	// Get 4D eye (Camera) coordinates
	auto rayEye = _inverseProjMatrix * rayClip;
	rayEye = Vector4f(rayEye[0], rayEye[1], -1.0, 0.0);

	// Get 4D world coordinates
	auto rayWorld = _inverseViewMatrix*rayEye;
	auto rayWorldVec3 = Vector3f(rayWorld[0], rayWorld[1], rayWorld[2]).normalized();

	return rayWorldVec3;
}

void Camera::calculateViewMatrix()
{
	auto R = _rotation.getMatrix();
	auto T = Matrix4x4<float>::translation(-_position);

	auto inverseR = R.transposed();
	auto inverseT = Matrix4x4<float>::translation(_position);

	_viewMatrix = R*T;
	_inverseViewMatrix = inverseT*inverseR;
}

Matrix4x4f Camera::getProjMatrix() const
{
	return _projMatrix;
}

Matrix4x4f Camera::getViewMatrix() const
{
	return _viewMatrix;
}
