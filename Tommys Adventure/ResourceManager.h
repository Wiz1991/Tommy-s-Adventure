#pragma once
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <assert.h>
#include <vector>
#include <iostream>

namespace Textures {
	enum ID {
		AIRPLANE,
		BACKGROUND,
		test
	};
}

template<typename Resource, typename Indentifier>
class ResourceManager
{
public:
	void load(Indentifier ID, const std::string filepath) {
		std::unique_ptr<Resource>resource(new Resource());
		if (!resource->loadFromFile(filepath)) {
			std::cout << "Failed to load texture " << filepath << std::endl;
		}
		mResourceMap.insert(std::make_pair(ID, std::move(resource)));
	}
	Resource& get(Indentifier ID) {
		auto found = mResourceMap.find(ID);

		return *found->second;
	}
	
private:
	std::map<Indentifier, std::unique_ptr<Resource>> mResourceMap;
};

