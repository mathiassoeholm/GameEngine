#version 400

in vec3 vp;
in vec2 texcoord;
uniform float time;
out vec2 tex;

void main ()
{
	gl_Position = vec4 (
		vp.x + (cos(time * 13) * 0.14)*(1-abs(vp.x)),
		vp.y * 1.1 + sin(time * 13) * 0.1,
		vp.z,
		1.0);
	tex = vec2(texcoord.x, texcoord.y);
}