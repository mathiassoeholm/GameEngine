#version 400

in vec3 vp;
in vec2 texcoord;
uniform float time;
out vec2 tex;

void main ()
{
	gl_Position = vec4 (
		vp.x + (cos(time * 2) * 0.14)*(1-abs(vp.x)),
		vp.y,// + (sin(time * 2) * 0.1)*(1-abs(vp.y)),
		vp.z,
		1.0);
	tex = texcoord;
}