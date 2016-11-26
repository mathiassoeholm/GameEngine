#version 400

struct DirectionalLight
{
	vec3 color;
	vec3 direction;
};

uniform sampler2D tex;
uniform mat3 normalMatrix;
uniform DirectionalLight[10] dirLights;
uniform int dirLightsCount;
uniform vec3 ambientColor;

in vec2 fragTexcoord;
in vec3 fragNormal;
in vec4 fragColor;

out vec4 finalColor;

void main ()
{
	vec4 color = vec4(ambientColor.r, ambientColor.g, ambientColor.b, 0);

	for(int i = 0; i < dirLightsCount; i++)
	{
		vec3 transformedNormal = normalize(normalMatrix * fragNormal.xyz);
		float brightness = dot(transformedNormal, dirLights[i].direction);
		brightness = clamp(brightness,0.0,1.0);

		color += brightness * vec4(dirLights[i].color, color.a);
	}

	finalColor = texture(tex, fragTexcoord) * color;
}