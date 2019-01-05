#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

namespace Textures {
	enum ID {
		Player,
		Enemy
	};



}
template<typename Resource, typename Indentifier>
class ResourceManager
{
public:
	void load(Indentifier ID, const std::string filepath);
	Resource& get(Indentifier ID);
    const Resource& get(Indentifier ID) const;
private:
	std::map<Indentifier, std::unique_ptr<Resource>> mResourceMap;
};

