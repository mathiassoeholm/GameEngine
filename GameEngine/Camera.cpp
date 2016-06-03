#include "Camera.h"

namespace GameEngine
{
	Camera::Camera() :
		nearClipPlane(0.1),
		farClipPlane(100),
		fieldOfView(67)
	{

	}

	GLfloat Camera::getNearClipPlane() const
	{
		return nearClipPlane;
	}

	void Camera::setNearClipPlane(const GLfloat &value)
	{
		nearClipPlane = value;
	}

	GLfloat Camera::getFarClipPlane() const
	{
		return farClipPlane;
	}

	void Camera::setFarClipPlane(const GLfloat &value)
	{
		farClipPlane = value;
	}

	GLfloat Camera::getFieldOfView() const
	{
		return fieldOfView;
	}

	void Camera::setFieldOfView(const GLfloat &value)
	{
		fieldOfView = value;
	}

	void Camera::update(Time &time)
	{
		projMatrix = glm::perspective(
				glm::radians(fieldOfView),
				(GLfloat)screenWidth/(GLfloat)screenHeight,
				nearClipPlane,
				farClipPlane);

		viewMatrix = glm::lookAt(
				getGameObject()->getPosition(),
				getGameObject()->getPosition() + getGameObject()->getForward(),
				getGameObject()->getUp());
	}

	void Camera::setScreenDimensions(const GLint &width, const GLint &height)
	{
		screenWidth = width;
		screenHeight = height;
	}

	int Camera::getOrder() const
	{
		return -10;
	}

	const glm::mat4& Camera::getProjMatrix() const
	{
		return projMatrix;
	}

	const glm::mat4 &Camera::getViewMatrix() const
	{
		return viewMatrix;
	}
}

