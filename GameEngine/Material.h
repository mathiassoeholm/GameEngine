#pragma once

#include <string>

namespace
{
	class Material
	{
	public:
		Material(std::string vertexShaderSource, std::string fragmentShaderSource);
		void use() const;
	};
}

