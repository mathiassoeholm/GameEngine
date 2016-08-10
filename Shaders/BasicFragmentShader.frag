#version 400

in vec4 tPos;
in vec4 tNormal;
in vec4 tColor;

out vec4 frag_colour;

void main ()
{
	frag_colour = tColor;
}