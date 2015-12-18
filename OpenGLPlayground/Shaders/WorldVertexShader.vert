﻿#version 400

in vec3 vp;

uniform mat4 viewMat, projMat;

void main ()
{
	gl_Position = projMat * viewMat * vec4(vp, 1.0);
}