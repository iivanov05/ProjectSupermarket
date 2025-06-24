#include <iostream>
#include "System.h"
#include <ctime>
#include "my_string.h"
#include "my_vector.h"
int main()
{
	time_t t = time(NULL);
	struct tm date = *localtime(&t);
	my_vector<my_string> data_time;
	char buffer[10];

	// Year (note: tm_year is years since 1900)
	std::sprintf(buffer, "%d", date.tm_year + 1900);
	data_time.push_back(buffer);

	// Month (tm_mon is 0–11, so add 1)
	std::sprintf(buffer, "%02d", date.tm_mon + 1);
	data_time.push_back(buffer);

	// Day
	std::sprintf(buffer, "%02d", date.tm_mday);
	data_time.push_back(buffer);

	// Hour
	std::sprintf(buffer, "%02d", date.tm_hour);
	data_time.push_back(buffer);

	// Minute
	std::sprintf(buffer, "%02d", date.tm_min);
	data_time.push_back(buffer);

	// Second
	std::sprintf(buffer, "%02d", date.tm_sec);
	data_time.push_back(buffer);

}
