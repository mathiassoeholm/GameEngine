#pragma once

#include "Mesh.h"

namespace GameEngine
{
	// Contains methods to construct primitive shapes as Mesh objects.
	class Primitives
	{
	public:
		static Mesh createTriangle();
		static Mesh createQuad();
		static Mesh createCube();
	};
}
