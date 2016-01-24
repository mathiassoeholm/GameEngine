#version 400

in vec4 vColor;
in vec3 positionEye, normalEye;

out vec4 frag_colour;

// Light properties
vec3 lightPosition = vec3(0.0, 0.0, 0.2);
vec3 spec = vec3(1.0, 1.0, 1.0);
vec3 diff = vec3(0.7, 0.7, 0.7);
vec3 amb = vec3(0.2, 0.2, 0.2);

// Surface properties
vec3 specRefl = vec3(1.0, 1.0, 1.0);
vec3 ambRefl = vec3(1.0, 1.0, 1.0);
float specExp = 16.0;

uniform mat4 viewMat;

void main ()
{
	vec3 ambient = amb * ambRefl;

	vec3 normal = normalize(normalEye);

	vec3 lightPosEye = vec3(viewMat * vec4(lightPosition, 1.0));
	vec3 lightDir = lightPosEye - positionEye;
	vec3 lightDirNormalized = normalize(lightDir);
	float lDot = max(dot(lightDirNormalized, normal), 0.0);

	vec3 surfaceToViewerEye = normalize(-positionEye);
	vec3 halfWayEye = normalize(surfaceToViewerEye + lightDirNormalized);
	float sDot = max(dot(halfWayEye, normal), 0.0);
	float specFactor = pow(sDot, specExp);

	frag_colour = vec4(vColor.rgb * diff + specRefl * spec * (sDot*sDot) + amb * ambRefl, 1.0);
}