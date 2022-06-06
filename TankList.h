#ifndef TANKLIST_H_
#define TANKLIST_H_
#include "tank.h"
#include <vector>

class TankList {
private:
	std::vector<Tank> tanks;

public:
	TankList();

	void add_fuel_tank(double);
	void list_fuel_tanks();
	void remove_fuel_tank(int);
	void break_fuel_tank(int);
	void repair_fuel_tank(int);
	void open_valve(int);
	void close_valve(int);

	void connect_fuel_tank_to_engine(int);
	void disconnect_fuel_tank_from_engine(int);
};

#endif /* TANKLIST_H_ */