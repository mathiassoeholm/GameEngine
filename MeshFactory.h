#pragma once

#include "Mesh.h"

class MeshFactory
{
public:
	static Mesh createTriangle();
	static Mesh createCube();
};