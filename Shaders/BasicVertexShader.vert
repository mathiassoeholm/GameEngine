#version 400

in vec3 vp;

uniform mat4 mvpMatrix;

void main()
{
	gl_Position = mvpMatrix * vec4(vp, 1.0);
}