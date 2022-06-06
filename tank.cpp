#include "tank.h"

int Tank::current_id = 0;

Tank::Tank(double capacity) : id(current_id++) {
	this->capacity = capacity;
	this->fuel_quantity = capacity; /// new tank is full
	broken = false;  /// new tank is not broken by default
	valve = false;	 /// new tanks valve is closed by default
}

Tank::Tank(const Tank& tank) {
	id = current_id++;
	capacity = tank.capacity;
	fuel_quantity = tank.fuel_quantity;
	broken = tank.broken;
	valve = tank.valve;
}

int Tank::get_id() const {
	return id;
}

double Tank::get_capacity() const {
	return capacity;
}

void Tank::set_capacity(double capacity) {
	this->capacity = capacity;
}

bool Tank::get_broken() const {
	return broken;
}

void Tank::set_broken(bool value) {
	broken = value;
}

bool Tank::get_valve() const {
	return valve;
}

void Tank::set_valve(bool isOpen) {
	valve = isOpen;
}

double Tank::get_fuel_quantity() const {
	return fuel_quantity;
}

void Tank::set_fuel_quantity(double quantity) {
	if (quantity <= capacity) {
		fuel_quantity = quantity;
	}
	else {
		fuel_quantity = capacity;
	}
}





