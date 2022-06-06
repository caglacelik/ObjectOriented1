
#ifndef ENGINE_H_
#define ENGINE_H_
#include "tank.h"
#include <vector>

class Engine
{
private:
	double fuel_per_second;
	bool status;

	Engine(double fuel_per_second = 0, bool status = false); ///constructor is private singleton design pattern
	static Engine e_Instance;
public:
	std::vector<Tank> connectedTanks;

	static Engine& Get() {
		return e_Instance;
	}

	Engine(const Engine&) = delete;

	double get_fuel_per_second() const;
	void set_fuel_per_second(double);

	bool get_status() const;

	void start_engine();
	void stop_engine();

	void absorb_fuel(double);
	void give_back_fuel(double);
	void stop_simulation();
};

#endif /* ENGINE_H_ */