#version 400

layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 normal;
out vec4 vColor;

uniform mat4 viewMat;
uniform mat4 projMat;
uniform mat4 modelMat;
uniform vec4 color; // Diffuse color

out vec3 positionEye, normalEye;

void main ()
{
	positionEye = vec3(viewMat * modelMat * vec4(vp, 1.0));
	normalEye = vec3(viewMat * modelMat * vec4(normal, 0.0));

	vColor = color;
	gl_Position =  projMat * vec4(positionEye, 1.0f);
}