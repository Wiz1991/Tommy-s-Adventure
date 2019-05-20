#pragma once
#include <Book/ResourceIdentifiers.hpp>
#include <vector>
#include <Book/Aircraft.hpp>
struct AircraftData {
	Textures::ID texture;
	float speed;
	int hitpoints;
};
std::vector<AircraftData> initiliazeAircraftData();