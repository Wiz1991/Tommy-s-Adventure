#include "..\Include\Book\DataTable.h"

std::vector<AircraftData> initiliazeAircraftData()
{
	std::vector<AircraftData> data(Aircraft::TypeCount);

	data[Aircraft::Eagle].hitpoints = 100;
	data[Aircraft::Eagle].speed = 250;
	data[Aircraft::Eagle].texture = Textures::Eagle;

	data[Aircraft::Raptor].hitpoints = 30;
	data[Aircraft::Raptor].speed = 170;
	data[Aircraft::Raptor].texture = Textures::Raptor;

	return data;
}