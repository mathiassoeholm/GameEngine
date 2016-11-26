#version 400

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texcoord;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec4 color;

uniform mat4 mvpMatrix;

out vec4 fragPos;
out vec2 fragTexcoord;
out vec3 fragNormal;
out vec4 fragColor;

void main()
{
	fragTexcoord = texcoord;
	fragNormal = normal;
	fragColor = color;

	gl_Position = mvpMatrix * vec4(pos, 1.0);
}