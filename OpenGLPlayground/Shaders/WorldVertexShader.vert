#version 400

in vec3 vp;
out vec4 vColor;

uniform mat4 viewMat;
uniform mat4 projMat;
uniform vec4 color;

void main ()
{
	vColor = color;
	gl_Position =  projMat * viewMat * vec4(vp, 1.0f);
}