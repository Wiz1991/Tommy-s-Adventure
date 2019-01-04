#include "ResourceManager.h"



template<typename Resource, typename Indentifier>
void ResourceManager<Resource, Indentifier>::load(Indentifier ID, const std::string filepath)
{
	std::unique_ptr<Resource>resource(new Resource());
	resource->loadFromFile(filepath);
	mResourceMap.insert(std::make_pair(ID, std::move(resource)));
}

template<typename Resource, typename Indentifier>
Resource & ResourceManager<Resource, Indentifier>::get(Indentifier ID)
{
	auto found = mResourceMap.find(ID);

	return *found->second;
}

template<typename Resource, typename Indentifier>
const Resource & ResourceManager<Resource, Indentifier>::get(Indentifier ID) const
{
	auto found = mResourceMap.find(ID);

	return *found->second;
}
