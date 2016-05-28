#pragma once

#include "Component.h"

namespace GameEngine
{
	class Camera : public Component
	{
		GLint screenWidth;
		GLint screenHeight;
		GLfloat nearClipPlane;
		GLfloat farClipPlane;
		GLfloat fieldOfView;
		glm::mat4 projMatrix;
		glm::mat4 viewMatrix;
	public:
		Camera();
		GLfloat getNearClipPlane() const;
		void setNearClipPlane(const GLfloat& value);
		GLfloat getFarClipPlane() const;
		void setFarClipPlane(const GLfloat& value);
		GLfloat getFieldOfView() const;
		void setFieldOfView(const GLfloat& value);
		const glm::mat4& getProjMatrix() const;
		const glm::mat4& getViewMatrix() const;
		void update(Time& time) override;
		int getOrder() const override;
		void setScreenDimensions(const GLint& width, const GLint& height);
	};
}