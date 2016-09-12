#version 400

in vec4 tPos;
in vec2 tTexcoord;
in vec4 tNormal;
in vec4 tColor;

out vec4 frag_colour;

uniform sampler2D tex;

void main ()
{
	frag_colour = texture(tex, tTexcoord) * tColor;
}