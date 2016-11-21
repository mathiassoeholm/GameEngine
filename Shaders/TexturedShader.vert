#version 400

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 texcoord;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec4 color;

struct DirectionalLight
{
	vec3 color;
	vec3 direction;
};

uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;
uniform DirectionalLight[10] dirLights;
uniform int dirLightsCount;
uniform vec3 ambientColor;

out vec4 tPos;
out vec2 tTexcoord;
out vec4 tNormal;
out vec4 tColor;

void main()
{
	tPos = mvpMatrix * vec4(pos, 1.0);
	tTexcoord = texcoord;
	tNormal = vec4(normal, 0.0);
	tColor = vec4(ambientColor.r, ambientColor.g, ambientColor.b, 0);

	for(int i = 0; i < dirLightsCount; i++)
	{
		vec3 transformedNormal = normalize(normalMatrix * tNormal.xyz);
		float brightness = dot(transformedNormal, dirLights[i].direction);
		brightness = clamp(brightness,0.0,1.0);
		tColor += brightness * vec4(dirLights[i].color, tColor.a);
		//tColor = vec4(1, 0, 0, 1);
	}

	gl_Position = tPos;
}