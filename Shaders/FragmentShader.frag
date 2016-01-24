#version 400

out vec4 frag_colour;
in vec2 tex;

uniform sampler2D s;

void main ()
{
	frag_colour = texture(s, tex);
	//frag_colour = vec4(tex.x, tex.x, tex.x, 1.0);
}