#pragma once
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <assert.h>
#include <vector>
namespace Textures {
	enum ID {
		AIRPLANE,
		BACKGROUND
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

typedef ResourceManager<sf::Texture, Textures::ID> TextureManager;