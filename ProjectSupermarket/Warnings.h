#pragma once
#include <iostream>
#include <fstream>
#include "my_string.h";


class Warning {

protected:
	my_string sender;
	my_string description;
	size_t critical_points = 0;
	 
	public:
		Warning();
		Warning& operator=(const Warning& other);
		~Warning() = default;

		my_string get_sender()const;
		my_string get_description()const;
		size_t get_critical_points()const;
};