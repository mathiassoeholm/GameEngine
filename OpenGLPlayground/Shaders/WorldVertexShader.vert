#version 400

in vec3 vp;

uniform mat4 modelMatrix;

void main()
{
	gl_Position = vec4(vp.x, vp.y, vp.z, 1.0) * modelMatrix;
}