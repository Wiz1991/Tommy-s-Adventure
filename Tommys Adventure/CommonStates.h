#pragma once
#include "Menu.h"
inline State* GetStateFromType(State::Type stateType) {
	switch (stateType) {
	case State::Type::INTRO:
		;
	case State::Type::MENU:
		return new Menu();
	default:
		return nullptr;



		//LIST OF ALL STATES, returns an object to RegisterStates()
	}
}