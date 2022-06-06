
#ifndef TANK_H_
#define TANK_H_

class Tank
{
private:
	int id;
	double capacity;
	bool broken;
	bool valve;
	double fuel_quantity;
public:
	static int current_id;  ///to auto increment the id's

	Tank(double capacity = 100); ///constructor with default parameter
	Tank(const Tank&); ///copy constructor

	int get_id() const;

	double get_capacity() const;
	void set_capacity(double);

	bool get_broken() const;
	void set_broken(bool);

	bool get_valve() const;
	void set_valve(bool);

	double get_fuel_quantity() const;
	void set_fuel_quantity(double);
};

#endif /* TANK_H_ */