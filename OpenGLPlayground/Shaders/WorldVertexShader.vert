#version 400

layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 normal;
out vec4 vColor;

uniform mat4 viewMat;
uniform mat4 projMat;
uniform vec4 color; // Diffuse color

// Light properties
vec3 lightPosition = vec3(10.0, 10.0, 10.0);
vec3 spec = vec3(1.0, 1.0, 1.0);
vec3 diff = vec3(0.7, 0.7, 0.7);
vec3 amb = vec3(0.2, 0.2, 0.2);

// Surface properties
vec3 specRefl = vec3(1.0, 1.0, 1.0);
vec3 ambRefl = vec3(1.0, 1.0, 1.0);
float specExp = 100.0;

void main ()
{
	vColor = color;
	gl_Position =  projMat * viewMat * vec4(vp, 1.0f);
}