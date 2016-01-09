#version 400

out vec4 frag_colour;
in vec4 vColor;

void main ()
{
	frag_colour = vColor;
}