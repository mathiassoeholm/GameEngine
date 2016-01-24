#version 400

in vec3 vp;

uniform mat4 viewMat;
uniform mat4 projMat;

void main ()
{
	gl_Position =  viewMat * vec4(vp, 1.0f);
}