#pragma once

#include <memory>
#include "Mesh.h"

namespace GameEngine
{
	// Contains methods to construct primitive shapes as Mesh objects.
	class Primitives
	{
	public:
		static std::shared_ptr<Mesh> createTriangle();
		static std::shared_ptr<Mesh> createQuad();
		static std::shared_ptr<Mesh> createCube();
	};
}
