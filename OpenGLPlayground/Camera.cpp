#include "Camera.h"

#define ONE_DEG_IN_RAD 0.017444444

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
}

void Camera::setPosition(Vector3f position)
{
	_position = position;
	calculateViewMatrix();
}

void Camera::setRotationn(Quaternionf rotation)
{
	_rotation = rotation;
	calculateViewMatrix();
}

void Camera::calculateViewMatrix()
{
	auto T = Matrix4x4<float>::translation(-_position);
	_viewMatrix = _rotation.getMatrix()*T;
}

Camera::Camera(GLFWwindow* window, Vector3f position, Quaternionf rotation) : _window(window), _position(position), _rotation(rotation)
{
	calculateViewMatrix();
}

Matrix4x4f Camera::getProjMatrix() const
{
	return _projMatrix;
}

Matrix4x4f Camera::getViewMatrix() const
{
	return _viewMatrix;
}
