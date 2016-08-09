#pragma once

#include "Component.h"
#include "Mesh.h"
#include "Material.h"
#include <memory>

namespace GameEngine
{
	class MeshRenderer : public Component
	{
		Mesh mesh;
		Material material;
	public:
		MeshRenderer(const Mesh& mesh, const Material& material);
		void update(const UpdateInfo& updateInfo) override;
		void onDestroy() override;
		int getOrder() const override;
	};
}
