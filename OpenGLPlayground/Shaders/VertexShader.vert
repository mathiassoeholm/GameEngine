#version 400

in vec3 vp;
in vec2 texcoord;
out vec2 tex;

void main ()
{
	gl_Position = vec4 (vp.x, vp.y, vp.z, 1.0);
	tex = texcoord;
}