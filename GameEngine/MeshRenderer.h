#pragma once

#include "Component.h"
#include "Mesh.h"
#include "Material.h"
#include <memory>

namespace GameEngine
{
	class MeshRenderer : public Component
	{
		Mesh& mesh;
		Material& material;
	public:
		MeshRenderer(Mesh& mesh, Material& material);
		void update() override;
		int getOrder() const override;
	};
}
