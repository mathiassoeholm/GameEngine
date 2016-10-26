#include "DirectionalLight.h"

namespace GameEngine
{
    DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 color) : Light(color),
        direction(direction)
    {

    }
}
