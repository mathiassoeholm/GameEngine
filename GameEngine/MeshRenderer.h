#pragma once

#include "Component.h"
#include "Mesh.h"
#include "Material.h"
#include <memory>

namespace GameEngine
{
	class MeshRenderer : public Component
	{
		std::shared_ptr<Mesh> mesh;
		std::shared_ptr<Material> material;
	public:
		MeshRenderer(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material);
		void update(const UpdateInfo& updateInfo) override;
		void onDestroy() override;
		int getOrder() const override;
	};
}
