#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include "my_string.h"
#include <ctime>

class Time {

	time_t t = time(NULL);
	tm* date = localtime(&t);

public:
	Time() = default;

	~Time() = default;

	my_string get_executuon_time();
};


