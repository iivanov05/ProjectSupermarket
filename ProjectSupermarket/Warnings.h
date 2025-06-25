#pragma once
#include <iostream>
#include <fstream>
#include "my_string.h";


class Warning {

private:
	my_string sender;
	my_string description;
	size_t critical_points = 0;
	my_string points_description;
	void set_points_description(const my_string& description);
	public:
		Warning() = default;
		Warning(const my_string& sender,
			const my_string& description,
			const size_t& critical_points);

		Warning& operator=(const Warning& other);
		~Warning() = default;

		
		my_string get_sender()const;
		my_string get_description()const;
		size_t get_critical_points()const;
		my_string get_points_description()const;
};