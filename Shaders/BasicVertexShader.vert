#version 400

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texcoord;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec4 color;

struct DirectionalLight
{
	vec3 color;
	vec3 direction;
};

uniform mat4 mvpMatrix;
uniform DirectionalLight[] dirLights;

out vec4 tPos;
out vec4 tNormal;
out vec4 tColor;

void main()
{
	tPos = mvpMatrix * vec4(pos, 1.0);
	tNormal = vec4(normal, 0.0);
	tColor = color;

	gl_Position = tPos;
}