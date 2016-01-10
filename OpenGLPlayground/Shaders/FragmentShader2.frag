#version 400

in vec4 vColor;
in vec3 positionEye, normalEye;

out vec4 frag_colour;

// Light properties
vec3 lightPosition = vec3(5.0, 5.0, 5.0);
vec3 spec = vec3(1.0, 1.0, 1.0);
vec3 diff = vec3(0.7, 0.7, 0.7);
vec3 amb = vec3(0.2, 0.2, 0.2);

// Surface properties
vec3 specRefl = vec3(1.0, 1.0, 1.0);
vec3 ambRefl = vec3(1.0, 1.0, 1.0);
float specExp = 100.0;

uniform mat4 viewMat;

void main ()
{
	vec3 ambient = amb * ambRefl;

	vec3 lightPosEye = vec3(viewMat * vec4(lightPosition, 1.0));
	vec3 lightDir = lightPosEye - positionEye;
	vec3 lightDirNormalized = normalize(lightDir);
	float lDot = max(dot(lightDirNormalized, normalEye), 0.0);

	frag_colour = vec4(ambient * lDot, 1.0);
}