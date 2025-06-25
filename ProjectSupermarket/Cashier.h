#pragma once
#include "my_vector.h"
#include "Employee.h"
#include "Warnings.h"


class Cashier : public Employee{

	size_t transactions = 0;
	my_vector <Warning> warnings;
public:
	Cashier() = default;

	Cashier(const size_t& id1,
		const my_string& name1,
		const my_string& surname1,
		const size_t& age1,
		const my_string& phone_number1,
		const my_string& password1,
		const size_t transacrions);

	~Cashier() override = default;

	void set_transactions(size_t transactions1);
	size_t get_points_from_all_warnings() const;
	size_t get_transactions()const;
	my_vector<Warning> get_warnings()const;
};