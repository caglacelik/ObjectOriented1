#include "engine.h"
#include "TankList.h"
#include <iostream>

Engine Engine::e_Instance;

Engine::Engine(double fuel_per_second, bool status) {
	this->fuel_per_second = fuel_per_second;
	this->status = status;
}


double Engine::get_fuel_per_second() const {
	return fuel_per_second;
}

void Engine::set_fuel_per_second(double fuel_per_second) {
	this->fuel_per_second = fuel_per_second;
}

bool Engine::get_status() const {
	return status;
}

void Engine::start_engine() {
	if (connectedTanks.size() > 0) {
		status = true;
	}
	else {
		std::cout << "Error there should be at least 1 connected tank to the engine" << std::endl;
	}
}

void Engine::absorb_fuel(double amount) {
	if (connectedTanks.size() > 0) {
		connectedTanks[0].set_fuel_quantity(connectedTanks[0].get_fuel_quantity() - amount);
	}
	else {
		std::cout << "There isn't any connected tank to engine" << std::endl;
	}
}

void Engine::give_back_fuel(double amount) {
	if (connectedTanks.size() > 0) {
		connectedTanks[0].set_fuel_quantity(connectedTanks[0].get_fuel_quantity() + amount);
	}
	else {
		std::cout << "There isn't any connected tank to engine" << std::endl;
	}
}

void Engine::stop_engine() {
	status = false;
}

void Engine::stop_simulation() {
	exit(0);
}
