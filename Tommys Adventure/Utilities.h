#pragma once
#include <sstream>

template <typename T>
std::string toString(T number) {
	std::ostringstream ss;
	ss << number;
	return ss.str();
}