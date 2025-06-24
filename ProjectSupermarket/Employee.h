#pragma once
#include "my_string.h"


class Employee {

	size_t id = 0;
	my_string name;
	my_string surname;
	size_t age = 0;
	my_string phone_number;
	my_string password;


	void set_id(size_t n);
	void set_name(my_string str);
	void set_surname(my_string str);
	void set_age(size_t n);
	void set_phone_number(my_string str);
	void set_password(my_string str);

public:

	Employee() = default;

	Employee(const size_t& id,
		const my_string& name,
		const my_string& surname,
		const size_t& age,
		const my_string& phone_number,
		const my_string& password);

	virtual ~Employee() = default;

	size_t get_id()const;
	my_string get_name()const;
	my_string get_surname()const;
	size_t get_age()const;
	my_string get_phone_number()const;
	my_string get_password()const;

};