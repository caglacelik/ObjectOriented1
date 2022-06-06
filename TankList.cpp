/*
 * TankList.cpp
 *
 *  Created on: Dec 9, 2020
 *      Author: burakkosova
 */

#include "TankList.h"
#include "engine.h"
#include <iostream>

TankList::TankList() {

}

void TankList::add_fuel_tank(double capacity) {
	Tank t(capacity);
	tanks.push_back(t);
}

void TankList::list_fuel_tanks() {
	for (int i = 0; i < tanks.size(); i++) {
		std::cout << "tank " << tanks[i].get_id()
			<< " capacity: " << tanks[i].get_capacity()
			<< " quantity: " << tanks[i].get_fuel_quantity()
			<< " broken: " << tanks[i].get_broken()
			<< " valve: " << tanks[i].get_valve() << std::endl;
	}
}

void TankList::remove_fuel_tank(int id) {
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id) {
			tanks.erase(tanks.begin() + i);
		}
	}
}

void TankList::break_fuel_tank(int id) {
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id) {
			tanks[i].set_broken(true);
		}
	}
}

void TankList::repair_fuel_tank(int id) {
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id) {
			tanks[i].set_broken(false);
		}
	}
}

void TankList::open_valve(int id) {
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id) {
			tanks[i].set_valve(true);
		}
	}
}

void TankList::close_valve(int id) {
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id) {
			tanks[i].set_valve(false);
		}
	}
}


void TankList::connect_fuel_tank_to_engine(int id) {
	Engine& e = Engine::Get();				/// gets the only engine instance
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id && !tanks[i].get_broken()) { ///if the tank is not broken connect to engine
			e.connectedTanks.push_back(tanks[i]);
			tanks[i].set_valve(true);					 ///open the valve since its connected to engine
		}
	}
}

void TankList::disconnect_fuel_tank_from_engine(int id) {
	Engine& e = Engine::Get();
	for (int i = 0; i < tanks.size(); i++) {
		if (tanks[i].get_id() == id) {
			e.connectedTanks.erase(e.connectedTanks.begin() + i);
			tanks[i].set_valve(false);                      ///close the valve
		}
		else {
			std::cout << "Tank not found!" << std::endl;
		}
	}
}


